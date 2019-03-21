%{
	#define YYSTYPE std::string
	#include <stdio.h>
	#include <iostream>
	#include <stack>
	#include <vector>
	#include <sstream>


	using namespace std;

	struct var{
		string name;
		long long int value;
	};

	struct tab{
		string name;
		vector<long long int> table;
		int min;
		int max;
	};
	
	void yyerror(const char *);
	int yylex();
	extern int yylineno;

	void finish();
	int find_var(string, vector<var>);
	int find_tab(string, vector<tab>);
	tab tab_cons(const char*, const char*, string);
	void cng_var(string, long long int, vector<var> *);
	long long int *get_var_tab(string, string, vector<tab>, vector<var>);
	long long int *get_var_tab_old(string, vector<tab>, vector<var>);
	long long int get_var_val(string, vector<var>);
	long long int get_num(string);
	long long int sanitize_val(string, vector<var>, vector<tab>, string);
	long long int adder(string, string);
	long long int subber(string, string);
	void multiplier(string, string);
	void divider(string, string);
	void modder(string, string);
	void is_equal(string, string);
	void is_nequal(string, string);
	void is_less(string, string);
	void is_bigg(string, string);
	void is_lesseq(string, string);
	void is_biggeq(string, string);
	void reset(string);
	int decrypt_reg(string);
	int read_in(string, vector<tab>, vector<var>);
	void write_out(string);
	string get_tab_name(string);
	void tab_write(string, string);
	void var_write(string, string);
	long long int get_val_num(string);
	void get_val_mem(string, string);
	string next_load_reg();
	int setup_val(string, long long int);
	void set_last_count_reg();
	void free_last_count_reg();
	int get_val_from_mem(string);
	void load_var_to_reg(string, string);
	int calc_addr(string);
	string encrypt_reg(int);

	void get(string);
	void put(string);
	void load(string);
	void store(string);
	void copy(string, string);
	void add(string, string);
	void sub(string, string);
	void half(string);
	void inc(string);
	void dec(string);
	void jump(int);
	void jzero(string, int);
	void jodd(string, int);
	void halt();

	long long int k = 0;
	vector<string> commands;
	vector<var> variables;
	vector<tab> tables;
	vector<var> for_variables;
	int tab_mode = 0;
	vector<long long int> regs = vector<long long int>(8,0);
	long long int last_calculated = -1;
	int last_loaded = 0;
	string last_reg = "G";
	string last_count_reg = "F";
	int count_check = 0;
	int read_var_check = 0;
	vector<long long int> if_beginers;
	vector<long long int> if_enders;
	vector<long long int> while_beginers;
	vector<long long int> while_middlers;
	vector<long long int> while_enders;
	vector<long long int> for_markers;
	int if_counter = -1;
%}

//%error-verbose
%token DECLARE IN END
%token IF THEN ELSE ENDIF
%token WHILE DO ENDWHILE ENDDO
%token FOR FROM TO DOWNTO ENDFOR
%token READ WRITE
%token SC
%token PLUS MINUS MULTI DIV MOD
%token EQ NEQ LES BIG LESEQ BIGEQ 
%token ASSIGN
%token OPEN CLOSE RANGE
%token NUM PIDENTIFIER
%%

program			:	DECLARE declarations IN commands END {//cout <<"ggggg";
finish(); 
printf("HALT\n");}
				;

declarations 	:	declarations PIDENTIFIER SC{ //cout << "zxvc";
							if(find_var($2, variables) == -1 && find_tab($2, tables) == -1){
								var v;
								v.name = $2;
								v.value = 0;
								variables.push_back(v);
							}else{
								printf("Blad: powtorna deklaracja zmiennej: %s \n", $2.c_str());
								return 0;
							}
						}
				|	declarations PIDENTIFIER OPEN NUM RANGE NUM CLOSE SC{		//printf("%s,%s,%s,%s,%s,%s,%s", $1.c_str(),$2.c_str(),$3.c_str(),$4.c_str(),$5.c_str(),$6.c_str(),$7.c_str());
							if(get_num($4) > get_num($6)){
								printf("Blad: niepoprawne wymiary tablicy: %s \n", $2.c_str());
								return 0;
							}else if(find_tab($2, tables) == -1 && find_var($2, variables) == -1){
								tab t =tab_cons($6.c_str(),$4.c_str(), $2);
								tables.push_back(t);
							}
							else{
								printf("Blad: powtorna deklaracja zmiennej: %s \n", $2.c_str());
								return 0;
							}
						}
				|	//
				;

commands		: 	commands command
				|	command
				;

command 		:	identifier ASSIGN expression SC
{//cout << "juz nie wiem";
				//printf("%s, %s, %s", $1.c_str(), $2.c_str(), $3.c_str());
				if(find_var($1, variables) == -1){
					//cout << get_tab_name($1);
					//cout << $1;
					if(find_tab(get_tab_name($1), tables) == -1){
						printf("Blad: zmienna %s niezadeklarowana\n", $1.c_str());
						return 0;
					}else{//cout << "AAAAAAAAAAAAAAAAA";
						//put(last_reg);
						if(count_check != 0){
							//put(last_count_reg);
							//cout << "tab count assign";
							tab_write($1, last_count_reg);
							free_last_count_reg();
						}else
							if(read_var_check != 0){
								load_var_to_reg($3, "F");
								tab_write($1, "F");
								read_var_check = 0;
								//cout << num << "   " << $3;
								//cout << to_string(num);
								//setup_val("H", get_num($3));
								//put("H");
						}else if(get_num($3) != -1){
							//setup_val("H", get_num($3));
							//put("H");
							tab_write($1, $3);
						}
							else{
								printf("Blad: niepoprawna zmienna do przypisania: %s\n", $3.c_str());
								return 0;
							}
					}
				}else{
					if(count_check != 0){
						//cout << last_count_reg;
						//put(last_count_reg);
						var_write($1, last_count_reg);
						free_last_count_reg();
					}else{
						//cout << "num";
						if(read_var_check != 0){
							load_var_to_reg($3, last_reg);
							var_write($1, last_reg);
							read_var_check = 0;
							//cout << num << "   " << $3;
							//cout << to_string(num);
							//setup_val("H", get_num($3));
							//put("H");
						}else if(get_num($3) != -1){
							//setup_val("H", get_num($3));
							//put("H");
							var_write($1, $3);
						}
						else{
							printf("Blad: niepoprawna zmienna do przypisania: %s\n", $3.c_str());
							return 0;
						}
					}
				}
}
				|	IF condition {
	if_beginers.push_back(k);
	k++;
	if_counter++;
	//cout << k;
	//put("B");
	//put("B");
	//put("B");
}
					THEN ifcommands{
	//put("A");
	//put("A");
	//put("A");
}
				|	{while_beginers.push_back(k);
						//put("B");
					} WHILE condition {while_middlers.push_back(k);} DO commands ENDWHILE{
	jump(while_beginers[while_beginers.size() - 1]);
	vector<string>::iterator pos = commands.begin();
	stringstream ss;
	ss << "JZERO B " << k + 1;		//chyba +1
	string ss_to_s = ss.str();
	commands.insert(pos + while_middlers[while_middlers.size() - 1] + 1, ss_to_s); 
	while_beginers.pop_back();
	while_middlers.pop_back();
}
				|	DO {while_beginers.push_back(k);
						//put("B");
					} commands WHILE condition ENDDO{
	jzero("B", k + 2);
	jump(while_beginers[while_beginers.size() - 1]);
	while_beginers.pop_back();
}
				|	FOR PIDENTIFIER FROM value {
	//put("A");
	//put("A");
	//put("A");
	//cout << find_tab($2, tables) << endl << find_var($2, variables);
	if(find_tab($2, tables) == -1 && find_var($2, variables) == -1){
		var v;
		v.name = $2;
		v.value = 0;
		//cout << variables.size();
		variables.push_back(v);
		//cout << variables.size();

		if(read_var_check != 0){
			load_var_to_reg($4, last_reg);
			var_write($2, last_reg);
			read_var_check = 0;
		}else if(get_num($4) != -1){
			var_write($1, $3);
		}
		else{
			printf("Blad: niepoprawna zmienna do przypisania: %s\n", $4.c_str());
		}

	}else{
		cout << "Blad: powtorna deklaracja zmiennej " << $2;
	}				//koniec tworzenia zmiennej		

	

} TO value DO {for_markers.push_back(k);} commands ENDFOR{

	//get_val_mem($7, "E");
	//put("E");
	

	get_val_mem($2, "D");
	inc("D");
	var_write($2, "D");//i++

	vector<string>::iterator pos = commands.begin();
	stringstream ss;
	ss << "JUMP " << k;		//mozliwe ze bez +1
	string ss_to_s = ss.str();
	commands.insert(pos + for_markers[for_markers.size() - 1] + 1, ss_to_s);
	for_markers.pop_back();

	next_load_reg();						//condition
	get_val_mem($2, "D");
	//cout << $2;
	put("A");
	put("D");
	get_val_mem($7, "E");
	put("A");
	load("E");
	put("E");
	//next_load_reg();
	//cout << $7;
	if(get_num($7) == -1)   
		is_lesseq("D", last_reg);
	else
		is_lesseq("D", $7);	//condition

	put("B");
	halt();
	jzero("B", k + 2);
	jump(for_markers[for_markers.size() - 1] + 1);

	//zamienic kolejnosc w pamieci tablicowych ze zwyklymi bo zapisanie forowej zmiennej moze nadpisac zmienna tablicowa(przekroczenie poprzedniego rozmiaru wektora)

}
				|	FOR PIDENTIFIER FROM value DOWNTO value DO commands ENDFOR
				|	READ identifier SC{
	if(read_in($2, tables, variables) != 0)
		cout << "Niepoprawna zmienna" << $2;
}
				|	WRITE value SC{
	//cout << $2;
	//cout << find_var($2, variables);
	if(find_var($2, variables) != -1 || find_tab(get_tab_name($2), tables) != -1){
		load_var_to_reg($2,"F");
		put("F");
		//put("F");
		//put("F");
		//cout << "inside";
	}else if(get_num($2) != -1){
		//write_out($2);
		setup_val("F",get_num($2));
		put("F");
		//put("F");
		//put("F");
	}else{
		printf("Blad: niepoprawna zmienna do wydrukowania: %s\n", $2.c_str());
		return 0;
	}
	read_var_check = 0;
}
				;

ifcommands		: commands {if_enders.push_back(k);} ELSE commands ENDIF{
	vector<string>::iterator pos = commands.begin();
	long long int jump = if_enders[if_beginers.size() - 1] + 1;
	stringstream ss;
	ss << "JZERO B " << to_string(if_enders[if_enders.size() - 1] + 2);
	string ss_to_s = ss.str();
	commands.insert(pos + if_beginers[if_beginers.size() - 1] + 1, ss_to_s); // + if_counter przy zagnieżdżonych
	stringstream ss2;
	ss2 << "JUMP " << k;
	string ss_to_s2 = ss2.str();
	commands.insert(pos + if_enders[if_enders.size() - 1] + 1, ss_to_s2);
	if_counter--;
	if_beginers.pop_back();
	if_enders.pop_back();
}
							| commands {if_enders.push_back(k);}ENDIF{
	//cout << k;
	vector<string>::iterator pos = commands.begin();
	long long int jump = if_enders[if_beginers.size() - 1] + 1;
	stringstream ss;
	//cout << if_counter;
	ss << "JZERO B " << k;
	string ss_to_s = ss.str();
	commands.insert(pos + if_beginers[if_beginers.size() - 1] + 1, ss_to_s); // + if_counter przy zagnieżdżonych
	if_counter--;
	if_beginers.pop_back();
	if_enders.pop_back();
}
							;

expression 		:	value
				|	value PLUS value{
	if(get_num($1) == -1){
		if(get_num($3) == -1){
			adder(next_load_reg(), last_reg);
		}
		else
			adder(last_reg, $3);
	}
	else{
		if(get_num($3) == -1){ 
			adder($1, last_reg);
		}
		else
			adder($1, $3);
	}
	set_last_count_reg();
}
				|	value MINUS value{
	if(get_num($1) == -1){
		if(get_num($3) == -1)   
			subber(next_load_reg(), last_reg);
		else
			subber(last_reg, $3);
	}
	else{
		if(get_num($3) == -1){ 
			subber($1, last_reg);
		}
		else
			subber($1, $3);
	}
	set_last_count_reg();
}
				|	value MULTI value{
	if(get_num($1) == -1){
		if(get_num($3) == -1)   
			multiplier(next_load_reg(), last_reg);
		else
			multiplier(last_reg, $3);
	}
	else{
		if(get_num($3) == -1){ 
			multiplier($1, last_reg);
		}
		else
			multiplier($1, $3);
	}
	set_last_count_reg();
}
				|	value DIV value{
	//put(next_load_reg());
	//put("A");
	//put("B");
	//put("C");
	//put("D");
	//put("E");
	//put("F");
	//put("G");
	//put("H");
	//cout << last_reg;
	//put(next_load_reg());
	//cout << $1 << "    " << $3;
	if(get_num($1) == -1){
		if(get_num($3) == -1)   
			divider(next_load_reg(), last_reg);
		else
			divider(last_reg, $3);
	}
	else{
		if(get_num($3) == -1){ 
			divider($1, last_reg);
		}
		else
			divider($1, $3);
	}
	set_last_count_reg();
}
				|	value MOD value{
	if(get_num($1) == -1){
		if(get_num($3) == -1)   
			modder(last_reg, next_load_reg());
		else
			modder(last_reg, $3);
	}
	else{
		if(get_num($3) == -1){ 
			modder($1, last_reg);
		}
		else
			modder($1, $3);
	}
	set_last_count_reg();
}
				;

condition		:	value EQ value{
	if(get_num($1) == -1){
		if(get_num($3) == -1)   
			is_equal(next_load_reg(), last_reg);
		else
			is_equal(last_reg, $3);
	}
	else{
		if(get_num($3) == -1){ 
			is_equal($1, last_reg);
		}
		else
			is_equal($1, $3);
	}
}
				|	value NEQ value{
	if(get_num($1) == -1){
		if(get_num($3) == -1)   
			is_nequal(next_load_reg(), last_reg);
		else
			is_nequal(last_reg, $3);
	}
	else{
		if(get_num($3) == -1){ 
			is_nequal($1, last_reg);
		}
		else
			is_nequal($1, $3);
	}
}
				|	value LES value{
	if(get_num($1) == -1){
		if(get_num($3) == -1)   
			is_less(next_load_reg(), last_reg);
		else
			is_less(last_reg, $3);
	}
	else{
		if(get_num($3) == -1){ 
			is_less($1, last_reg);
		}
		else
			is_less($1, $3);
	}
}
				|	value BIG value{
	if(get_num($1) == -1){
		if(get_num($3) == -1)   
			is_bigg(next_load_reg(), last_reg);
		else
			is_bigg(last_reg, $3);
	}
	else{
		if(get_num($3) == -1){ 
			is_bigg($1, last_reg);
		}
		else
			is_bigg($1, $3);
	}
}
				|	value LESEQ value{
	if(get_num($1) == -1){
		if(get_num($3) == -1)   
			is_lesseq(next_load_reg(), last_reg);
		else
			is_lesseq(last_reg, $3);
	}
	else{
		if(get_num($3) == -1){ 
			is_lesseq($1, last_reg);
		}
		else
			is_lesseq($1, $3);
	}
}
				|	value BIGEQ value{
	if(get_num($1) == -1){
		if(get_num($3) == -1)   
			is_biggeq(next_load_reg(), last_reg);
		else
			is_biggeq(last_reg, $3);
	}
	else{
		if(get_num($3) == -1){ 
			is_biggeq($1, last_reg);
		}
		else
			is_biggeq($1, $3);
	}
}
				;

value			:	NUM
				|	identifier{
	//$$ = last_reg;
	read_var_check = 1;
	//put("G");
	//put("H");
	//put(last_reg);
	//setup_val("H", 12345);
	//put("H");
}
				;

identifier 		:	PIDENTIFIER{//printf("empty");
	next_load_reg();	
	get_val_mem($1, last_reg);
	//cout << $1 << "\n\n\n\n" << last_reg;
	//put(last_reg);
	last_loaded = 1;
}
				|	PIDENTIFIER OPEN PIDENTIFIER CLOSE{//printf("pid");
	$$ = $1 + "(" + $3 + ")";
	tab_mode = 1;
	//printf("%s", $$.c_str());
	stringstream ss;
	ss << $1 << "(" << $3 << ")";
	string ss_to_s = ss.str(); 
	get_val_mem(ss_to_s, next_load_reg());
	last_loaded = 1;
}
				|	PIDENTIFIER OPEN NUM CLOSE{//printf("num");
	$$ = $1 + "(" + $3 + ")";	
	tab_mode = 1;
	//printf("%s", $$.c_str());
	stringstream ss;
	ss << $1 << "(" << $3 << ")";
	string ss_to_s = ss.str(); 
	//cout << ss_to_s << "    " << last_reg << "\n";
	//put("A");
	//put("A");
	//put("A");
	//put("G");
	//put("H");
	next_load_reg();
	get_val_mem(ss_to_s, last_reg);
	//put("G");
	//put("H");
	//put("A");
	//put("A");
	//put("A");	
	//put(last_reg);
	last_loaded = 1;
}
				;
%%

void load_var_to_reg(string var, string reg){
	int addr = calc_addr(var);
	//cout << var << find_var(var, variables) << " " << addr;
	//cout << "laod " << var << "->" << reg << "addr" << addr;
	setup_val("A", addr);
	//put("A");
	load(reg);
	//put(reg);
}

string get_tab_name(string s){
	int size = s.length();
	string name = "";
	for(int i = 0; i < size; i++)
		if(s.substr(i, 1) == "(")
			name = s.substr(0, i);
	return name;
}

void finish(){
	//cout << "ebebebebeb";
	for(int i = 0; i < commands.size(); i++){
		cout << commands[i] << endl;
	}
}

long long int sanitize_val(string s, vector<var> var_set, vector<tab> tab_set, string reg){
	//cout << s;
	if(get_num(s) != -1){
		//cout << "getvarval: " << get_num(s) << "\n";
		return get_num(s);
	}
	else{
		//put("A");
		if(calc_addr(s) != -1){
			setup_val("A", calc_addr(s));
			load(reg);
			//put("A");
			//put(reg);
			return -2;
		}
	}
	return -1;
}

int find_var(string name, vector<var> var_set){
	int s = var_set.size();
	//cout << s;
	for(int i = 0; i < s; i++){
		if(var_set[i].name == name)
			return i;
	}
	return -1;
}

int find_tab(string name, vector<tab> tab_set){
	//printf("%s, %d\n", name.c_str(), tab_set.size());
	int s = tab_set.size();
	//printf("%s, %d\n", name.c_str(), s);
	for(int b = 0; b < s; b++){
		//printf("petla %d", b);
		if(tab_set[b].name == name){
			//printf("index %d",b);
			return b;
		}
	}
	//printf("saddnes");
	return -1;
}

tab tab_cons(const char* max, const char* min, string n){
	//cout << std::numeric_limits<std::size_t>::max;
	tab t;
	t.name = n;
	long long int size = atoll(max) - atoll(min) + 1;
	t.table = vector<long long int>(size, 0);
	t.min = atoi(min);
	t.max = atoi(max);
	return t;
}

void cng_var(string name, long long int val, vector<var> *var_set){
	long long int i = find_var(name, *var_set);
	var_set->at(i).value = val;
}

long long int *get_var_tab(string pid, string ind, vector<tab> tab_set, vector<var> var_set){
	int size = pid.length();
	int num;
	string name;
	//printf("%s,%s,%d\n", pid.c_str(), ind.c_str(), tab_mode);
	if(tab_mode){
		//printf("%d\n", find_tab(pid, tab_set));
		
		if(find_tab(pid, tab_set) != -1){
			//printf("%lld", get_var_val(ind, var_set));
			if(int i=get_var_val(ind, var_set) != -1){
				return &tab_set[num].table[i - tab_set[num].min];
			}
		}
	}
	if(num=find_var(pid, var_set) != -1)
		return &var_set[find_var(pid, var_set)].value;
	return NULL;
}

long long int *get_var_tab_old(string pid, vector<tab> tab_set, vector<var> var_set){
	int size = pid.length();
	int num;
	string name;
	//printf("%s, LENGTH: %d", pid.c_str(), size);
	for(int i = 0; i < size; i++){
		//printf("%s\n", pid.substr(i, 1).c_str());
		if(pid.substr(i, 1) == "("){
			name = pid.substr(0, i);
			//printf("%sasdfasdf%s", name.c_str(), pid.c_str());
			int j = find_tab(name, tab_set);
			//printf("%d",j);
			if(j != -1){
				string ss = pid.substr(i + 1, size - i - 2);
				//printf("j = %d, indexs = %s,index =  %lld, min = %d, max = %d", j, ss.c_str(), get_var_val(ss, var_set), tab_set[j].min, tab_set[j].max);
				if(get_var_val(pid.substr(i + 1, size - i - 2), var_set) >= tab_set[j].min && get_var_val(pid.substr(i + 1, size - i - 2), var_set) <= tab_set[j].max)
					return &tab_set[j].table[get_var_val(pid.substr(i + 1, size - i - 2), var_set) - tab_set[j].min];
			}
		}		
	}
	if(num=find_var(pid, var_set) != -1)
		return &var_set[find_var(pid, var_set)].value;
	return NULL;
}

long long int get_var_val(string s, vector<var> var_set){
	long long int num;	
	//printf("vvv%svvv", s.c_str());
	if(num=get_num(s) != -1){
		//printf("numcheck: %lld", get_num(s));
		return get_num(s);
}
	else
		if(num=find_var(s, var_set) != -1)
			return var_set[num].value;
		else
			return -1;
}

long long int get_num(string s){
	int size = s.length();
	//s = s.substr(0, size - 1);
	//cout << "\ns : " << s; 
	for(int i = 0; i < size; i++){
		//cout << "\ndigit : " << i << s.at(i) << "\n";
		if(!isdigit(s.at(i)))
			return -1;
	}
	//printf("after numcheck");
	long long int num = atoll(s.c_str());
	//printf("\nreturn :%lld", num);
	return num;
}

int is_reg(string s){
	if(s == "A"||
	s == "B"||
	s == "C"||
	s == "D"||
	s == "E"||
	s == "F"||
	s == "G"||
	s == "H")
		return 1;
	else 
		return 0;
}

void fix_jumps_if(long long int pos){
	//for(long long int i = pos; 
}

void is_equal(string a, string b){
	reset("A");
	reset("B");
	long long int ai = sanitize_val(a, variables, tables, "C");
	long long int bi = sanitize_val(b, variables, tables, "B");
	int aa = 0, bb = 0;
	copy("A","C");
	if(ai == -1){
		if(is_reg(a))	
			copy("A", a);
		else
			printf("Blad: Niepoprawna wartość do dodania");
	}else{ 
		if(ai != -0)
			setup_val("A", ai);
	}
	if(bi == -1){
		if(is_reg(b))	
			copy("B", b);
		else
			printf("Blad: Niepoprawna wartość do dodania");
	}else{
		if(bi != 0)
			setup_val("B", bi);
	}
	//put("A");
	//put("B");
	copy("C","A");
	sub("A","B");
	jump(k + 4);
	sub("B","C");
	jzero("B",k + 4);
	jump(k + 6);
	jzero("A",k - 3);
	jump(k + 4);
	sub("B","B");
	inc("B");
	jump(k + 2);
	sub("B","B");
}

void is_nequal(string a, string b){
	reset("A");
	reset("B");
	long long int ai = sanitize_val(a, variables, tables, "C");
	long long int bi = sanitize_val(b, variables, tables, "B");
	int aa = 0, bb = 0;
	copy("A","C");
	if(ai == -1){
		if(is_reg(a))	
			copy("A", a);
		else
			printf("Blad: Niepoprawna wartość do dodania");
	}else{ 
		if(ai != -0)
			setup_val("A", ai);
	}
	if(bi == -1){
		if(is_reg(b))	
			copy("B", b);
		else
			printf("Blad: Niepoprawna wartość do dodania");
	}else{
		if(bi != 0)
			setup_val("B", bi);
	}
	//put("A");
	//put("B");
	copy("C","A");
	sub("A","B");
	jump(k + 4);
	sub("B","C");
	jzero("B",k + 4);
	jump(k + 5);
	jzero("A",k - 3);
	jump(k + 3);
	sub("B","B");
	jump(k + 3);
	sub("B","B");
	inc("B");
}

void is_less(string a, string b){
	reset("A");
	reset("B");
	long long int ai = sanitize_val(a, variables, tables, "C");
	long long int bi = sanitize_val(b, variables, tables, "B");
	int aa = 0, bb = 0;
	copy("A","C");
	if(ai == -1){
		if(is_reg(a))	
			copy("A", a);
		else
			printf("Blad: Niepoprawna wartość do dodania");
	}else{ 
		if(ai != -0)
			setup_val("A", ai);
	}
	if(bi == -1){
		if(is_reg(b))	
			copy("B", b);
		else
			printf("Blad: Niepoprawna wartość do dodania");
	}else{
		if(bi != 0)
			setup_val("B", bi);
	}
	//put("A");
	//put("B");
	sub("B","A");
	jzero("B",k + 4);
	sub("B","B");
	inc("B");
	jump(k + 2);
	sub("B","B");
}

void is_bigg(string a, string b){
	reset("A");
	reset("B");
	long long int ai = sanitize_val(a, variables, tables, "C");
	long long int bi = sanitize_val(b, variables, tables, "B");
	int aa = 0, bb = 0;
	copy("A","C");
	if(ai == -1){
		if(is_reg(a))	
			copy("A", a);
		else
			printf("Blad: Niepoprawna wartość do dodania");
	}else{ 
		if(ai != -0)
			setup_val("A", ai);
	}
	if(bi == -1){
		if(is_reg(b))	
			copy("B", b);
		else
			printf("Blad: Niepoprawna wartość do dodania");
	}else{
		if(bi != 0)
			setup_val("B", bi);
	}
	//put("A");
	//put("B");
	sub("A","B");
	jzero("A",k + 4);
	sub("B","B");
	inc("B");
	jump(k + 2);
	sub("B","B");
}

void is_lesseq(string a, string b){
	reset("A");
	reset("B");
	//put(a);
	//put(b);
	long long int ai = sanitize_val(a, variables, tables, "C");
	long long int bi = sanitize_val(b, variables, tables, "B");
	int aa = 0, bb = 0;
	copy("A","C");
	if(ai == -1){
		if(is_reg(a))	
			copy("A", a);
		else
			printf("Blad: Niepoprawna wartość do dodania");
	}else{ 
		if(ai != -0)
			setup_val("A", ai);
	}
	if(bi == -1){
		if(is_reg(b))	
			copy("B", b);
		else
			printf("Blad: Niepoprawna wartość do dodania");
	}else{
		if(bi != 0)
			setup_val("B", bi);
	}
	//put("A");
	//put("B");
	sub("A","B");
	jzero("A",k + 3);
	sub("B","B");
	jump(k + 3);
	sub("B","B");
	inc("B");
}

void is_biggeq(string a, string b){
	reset("A");
	reset("B");
	long long int ai = sanitize_val(a, variables, tables, "C");
	long long int bi = sanitize_val(b, variables, tables, "B");
	int aa = 0, bb = 0;
	copy("A","C");
	if(ai == -1){
		if(is_reg(a))	
			copy("A", a);
		else
			printf("Blad: Niepoprawna wartość do dodania");
	}else{ 
		if(ai != -0)
			setup_val("A", ai);
	}
	if(bi == -1){
		if(is_reg(b))	
			copy("B", b);
		else
			printf("Blad: Niepoprawna wartość do dodania");
	}else{
		if(bi != 0)
			setup_val("B", bi);
	}
	//put("A");
	//put("B");
	sub("B","A");
	jzero("B",k + 3);
	sub("B","B");
	jump(k + 3);
	sub("B","B");
	inc("B");
}

long long int adder(string a, string b){
	//put(a);
	//put(b);
	reset("A");
	reset("B");
	//cout << a;
	long long int ai = sanitize_val(a, variables, tables, "C");
	long long int bi = sanitize_val(b, variables, tables, "B");
	int aa = 0, bb = 0;
	//cout << a << " " << ai;
	//put("H");
	//put("G");
	copy("A","C");
	//put("G");
	//put("B");
	if(ai == -1){
		if(is_reg(a))	
			copy("A", a);
		else
			printf("Blad: Niepoprawna wartość do dodania");
	}else{ 
		if(ai != -0)
			setup_val("A", ai);
	}
	//put("A");
	if(bi == -1){
		if(is_reg(b))	
			copy("B", b);
		else
			printf("Blad: Niepoprawna wartość do dodania");
	}else{
		if(bi != 0)
			setup_val("B", bi);
	}
	//put(a);
	//put("A");
	//put("B");
	add("A","B");
	regs[0] = ai + bi;
	//put("A");
	return regs[0];
}

long long int subber(string a, string b){
	reset("A");
	reset("B");
	long long int ai = sanitize_val(a, variables, tables, "C");
	long long int bi = sanitize_val(b, variables, tables, "B");
	int aa = 0, bb = 0;
	//put("A");
	//put("B");
	copy("A","C");
	if(ai == -1){
		if(is_reg(a))	
			copy("A", a);
		else
			printf("Blad: Niepoprawna wartość do odejmowania");
	}else{ 
		if(ai != 0)
			setup_val("A", ai);
	}
	if(bi == -1){
		if(is_reg(b))	
			copy("B", b);
		else
			printf("Blad: Niepoprawna wartość do odejmowania");
	}else{
		if(bi != 0)
			setup_val("B", bi);
	}
	//put("A");
	//put("B");
	sub("A","B");
	//put("A");
	regs[0] = ai + bi;
	return regs[0];
}

void multiplier(string as, string bs){
	reset("A");
	reset("B");
	long long int ai = sanitize_val(as, variables, tables, "C");
	long long int bi = sanitize_val(bs, variables, tables, "B");
	int aa = 0, bb = 0;
	//put("A");
	//put("B");
	copy("A","C");
	if(ai == -1){
		if(is_reg(as))	
			copy("A", as);
		else
			printf("Blad: Niepoprawna wartość do mnozenia");
	}else{ 
		if(ai != 0)
			setup_val("A", ai);
	}
	if(bi == -1){
		if(is_reg(bs))	
			copy("B", bs);
		else
			printf("Blad: Niepoprawna wartość do mnozenia");
	}else{
		if(bi != 0)
			setup_val("B", bi);
	}

	copy("C", "A");
	sub("C","B");				//ustawienie wiekszej liczby na A
	jump(k + 4);
	copy("C", "A");
	copy("A", "B");
	copy("B", "C");
	jzero("C", k - 3);	//ustawienie wiekszej liczby na A

	reset("C");
	inc("C");
	copy("D","B");			//dodawańsko
	sub("D","C");
	jzero("D", k + 5);
	add("A","A");
	add("C","C");
	jump(k - 5);				//dodawańsko

	jump(k + 4);				//jeśli B to potega 2
	copy("D","C");
	sub("D","B");
	jzero("D", k + 21);

	copy("D","B");			// buduje D - pozostałe A do dodania		[new]	
	half("C");
	sub("D","C");				// D skonczone	[new]
	
	add("C","C");
	copy("B","A");
	half("A");
	half("B");
	half("C");
	copy("E","D");
	sub("E","C");
	jzero("E", k + 2);

	jump(k + 5);
	copy("E","C");
	sub("E","D");
	jzero("E", k + 7);
	jump(k - 9);

	sub("D","C");
	add("A","B");
	//copy("E","D");
	//dec("E");						//xxx
	//jzero("E", k + 4);	//xxx
	jzero("D", k + 4);	// wyjscie [new]
	//jump(k - 9);				// xxx
	jump(k - 13);	//xxx/////////////////////////////////
	jump(k + 2);
	add("A","B");
	
			//wynik A
	
}

void divider(string as, string bs){
	reset("A");
	reset("B");
	//cout << bs;
	//put(as);
	//put(bs);
	long long int ai = sanitize_val(as, variables, tables, "C");
	long long int bi = sanitize_val(bs, variables, tables, "B");
	int aa = 0, bb = 0;
	//cout << ai << bi;
	copy("A","C");
	if(ai == -1){
		if(is_reg(as))	
			copy("A", as);
		else
			printf("Blad: Niepoprawna wartość do dzielenia");
	}else{ 
		if(ai != -2)
		setup_val("A", ai);
	}
	if(bi == -1){
		if(is_reg(bs))	
			copy("B", bs);
		else
			printf("Blad: Niepoprawna wartość do dzielenia");
	}else{
		if(bi != -2){
			setup_val("B", bi);
			//cout << bi;
		}
	}
	reset("C");
	reset("D");
	//put("A");
	//put("B");			///////
	jzero("A", k + 10);
	jzero("B", k + 9);
	jump(k + 10);		///////
	copy("C","B");
	sub("C","A");
	jump(k + 4);
	reset("A");
	inc("A");
	jump(k + 47);
	jzero("C", k - 3);
	reset("A");				///////
	jump(k + 44);		///////
	copy("C","A");
	sub("C","B");
	jzero("C", k - 11);	///////
	copy("C","A");				///////
	sub("C","B");
	reset("D");
	jzero("C", k + 36);
	copy("C","B");
	inc("D");
	reset("E");
	inc("E");
	jzero("E",k + 6);
	add("C","C");
	add("D","D");
	copy("E","A");
	sub("E","C");
	jump(k - 5);
	
	copy("E","C");
	sub("E","A");
	jzero("E", k + 23);

	half("C");
	half("D");			///////
	copy("B","C");
	copy("E","D");
	reset("F");
	inc("F");
	jzero("F", k + 12);	///////
	jump(k + 3);	
	sub("C","B");
	sub("D","E");		///////
	half("B");
	jzero("B", k + 11);
	half("E");
	add("C","B");
	add("D","E");
	copy("F","A");
	sub("F", "C");
	jump(k - 11);
	copy("F","C");
	sub("F","A");
	jzero("F",k + 2);
	jump(k - 13);
	copy("A","D");
	//put("B");
	//put("C");
	//put("D");
	//put("E");
	//put("F");
			//wynik A z D 
}

void modder(string as, string bs){
	reset("A");
	reset("B");
	long long int ai = sanitize_val(as, variables, tables, "C");
	long long int bi = sanitize_val(bs, variables, tables, "B");
	int aa = 0, bb = 0;
	copy("A","C");
	//put("A");
	//put("B");
	if(ai == -1){
		if(is_reg(as))	
			copy("A", as);
		else
			printf("Blad: Niepoprawna wartość do dzielenia");
	}else{ 
		if(ai != -2)
			setup_val("A", ai);
	}
	if(bi == -1){
		if(is_reg(bs))	
			copy("B", bs);
		else
			printf("Blad: Niepoprawna wartość do dzielenia");
	}else{
		if(bi != -2)
			setup_val("B", bi);
	}
	reset("C");
	reset("D");
	//put("A");
	//put("B");			///////
	jzero("A", k + 10);
	jzero("B", k + 8);
	jump(k + 9);		///////
	copy("C","B");
	sub("C","A");
	jump(k + 4);
	reset("A");
	//inc("A");
	jump(k + 44);
	jzero("C", k - 2);
	reset("A");				///////
	jump(k + 41);		///////
	copy("C","A");
	sub("C","B");
	jzero("C", k - 10);	///////
	copy("C","A");				///////
	sub("C","B");
	reset("D");
	jzero("C", k + 33);
	copy("C","B");
	inc("D");
	reset("E");
	inc("E");
	jzero("E",k + 6);
	add("C","C");
	add("D","D");
	copy("E","A");
	sub("E","C");
	jump(k - 5);
	half("C");
	half("D");			///////
	copy("B","C");
	copy("E","D");
	reset("F");
	inc("F");
	jzero("F", k + 12);	///////
	jump(k + 3);	
	sub("C","B");
	sub("D","E");		///////
	half("E");
	jzero("E", k + 11);
	half("B");
	//put("C");
	add("C","B");
	add("D","E");
	copy("F","A");
	sub("F", "C");
	jump(k - 11);
	copy("F","C");
	sub("F","A");
	jzero("F",k + 2);
	jump(k - 13);
	sub("A","C");
	//put("C");
	//put("A");
			//wynik A
}

void set_last_count_reg(){
	//put("A");
	if(last_count_reg == "F"){
		last_count_reg = "E";
		copy("E","A");
	}
	else{
		last_count_reg = "F"; 
		copy("F","A");
	}
	count_check = 1;
}

void free_last_count_reg(){
	last_count_reg = "E";
	count_check = 0;
}

int decrypt_reg(string s){
	if(s=="A")
		return 0;
	if(s=="B")
		return 1;
	if(s=="C")
		return 2;
	if(s=="D")
		return 3;
	if(s=="E")
		return 4;
	if(s=="F")
		return 5;
	if(s=="G")
		return 6;
	
		return 7;
}

int setup_val(string reg, long long int val){
	reset(reg);
	if(val < 0)
		return -1;
	if(val == 0){
		reset(reg);
		return 0;
	}	
	inc(reg);
	if(val == 1)
		return 1;
	//cout << val;
	long long int a = 1;
	while(a * 2 < val){
		add(reg, reg);
		a *= 2;
	}
	if(a == val){
		last_calculated = a;
		return a;
	}
	string reg2 = "D";
	//cout << reg2;
	reset(reg2);
	copy(reg2, reg);
	long long int b = a;
	//half(reg2);
	while(b > 0){
		if(b + a <= val){
			a += b;
			add(reg,reg2);
			//put(reg);
		}
		if(a == val){
			last_calculated = a;
			//put(reg);
			return a;
		}else{
			b /= 2;
			half(reg2);
		}	
	}
	return -1;	
}

string encrypt_reg(int reg){
	if(reg == 0)
		return "A";
	if(reg == 1)
		return "B";
	if(reg == 2)
		return "C";
	if(reg == 3)
		return "D";
	if(reg == 4)
		return "E";
	if(reg == 5)
		return "F";
	if(reg == 6)
		return "G";
	if(reg == 7)
		return "H";
	return "ABCDEFGH";
}

int calc_addr(string var){
	int size = var.size();
	int num;
	string name;
	for(int i = 0; i < size; i++){
		if(var.substr(i, 1) == "("){
			name = var.substr(0, i);
			int j = find_tab(name, tables);
			if(j != -1){
				string ss = var.substr(i + 1, size - i - 2);
				if(get_var_val(ss, variables) >= tables[j].min && get_var_val(ss, variables) <= tables[j].max){
					int addr = variables.size();
					for(int k = 0; k < j; k++)
						addr += tables[k].table.size();
					addr += get_var_val(ss, variables) - tables[j].min;
					return addr;
				}
			}
		}		
	}
	if(find_var(var, variables) != -1){
		return find_var(var, variables);
	}
	return -1;
}

int get_val_from_mem(string var){
	int addr = calc_addr(var);
	if(addr != -1){
		setup_val("A", addr);
		load("B");
		return 0;
	}
	return -1;
}

void write_out(string id){
	long long int val = atoll(id.c_str());
	if(is_reg(id)){
		get_val_from_mem(id);
		//put("B");
		return;
	}
	if(val != -1){
		//printf("%lld",val);
		setup_val("A", val);
		//put("A");
		return;
	}	
}

int read_in(string s, vector<tab> tab_set, vector<var> var_set){
	int addr = calc_addr(s);
	if(addr == -1)
		return -1;
	setup_val("A", addr);
	get(next_load_reg());
	store(last_reg);
	return 0;
}

void tab_write_old(string tab, string val){
	put(val);
	int size = tab.length();
	string name = "";
	long long int ind = -1;
	for(int i = 0; i < size; i++)
		if(tab.substr(i, 1) == "("){
			name = tab.substr(0, i);
			ind = atoll(tab.substr(i + 1, size - i - 2).c_str());
			int addr = variables.size();
			for(int k = 0; k < find_tab(name, tables); k++)
				addr += tables[k].table.size();
			addr += ind - tables[find_tab(name, tables)].min;
			setup_val("A", addr);
			if(is_reg(val)){
				store(val);
			}else{
			long long int value = sanitize_val(val, variables, tables, "B");
			if(value > 0)
				setup_val("B", value);
			store("B");
			}
			return;
		}
}

void tab_write(string tab, string val){
	//put(val);
	int addr = calc_addr(tab);
	setup_val("A", addr);
	
	if(is_reg(val))
		store(val);
	else{
		setup_val("B", get_num(val));
		store("B");
	}
}

void var_write(string var, string val){
	int v = find_var(var, variables);
	setup_val("A", v);
	
	//put("A");
	//cout << "var_write: " << v << "  " << val;
	if(is_reg(val))
		store(val);
	else{
	//cout << val;
	//cout << get_num(val);	
	setup_val("B", get_num(val));
	//put("B");
	store("B");
	}
}

void for_var_write(string var, string val){
	int v = find_var(var, for_variables);
	v += variables.size();
	for(int i = 0; i < tables.size(); i++){
		v += tables[i].table.size();
	}
	setup_val("A", v);
	
	//put("A");
	//cout << "var_write: " << v << "  " << val;
	if(is_reg(val))
		store(val);
	else{
	//cout << val;
	//cout << get_num(val);	
	setup_val("B", get_num(val));
	//put("B");
	store("B");
	}
}

string next_load_reg(){
	if(last_reg == "G"){
		last_reg = "H";
	}else{
		last_reg = "G";
	}
	return last_reg;
}

void get_val_mem(string s, string reg){
	//put("G");
	//put("G");
	//put("H");
	int size = s.length();
	string name = "";
	long long int ind = -1;
	//cout << s << "    " << reg << "\n";
	for(int i = 0; i < size; i++)
		if(s.substr(i, 1) == "("){
			name = s.substr(0, i);
			ind = atoll(s.substr(i + 1, size - i - 2).c_str());
			int addr = variables.size();
			for(int k = 0; k < find_tab(name, tables); k++)
				addr += tables[k].table.size();
			addr += ind - tables[find_tab(name, tables)].min;
			setup_val("A", addr);
			load(reg);
			//put("A");
			//put("A");
			//put(reg);
			//put("G");
			//put("H");
			return;
		}
	int v = find_var(s, variables);
	setup_val("A", v);
	load(reg);
	//put("A");
	//put(reg);
}

void reset(string ind){
	regs[decrypt_reg(ind)] = 0;
	sub(ind, ind);
}

void get(string i){
	stringstream s;
	s << "GET " << i;
	k++;
	commands.push_back(s.str());
}

void put(string i){
	stringstream s;
	s << "PUT " << i;
	k++;
	commands.push_back(s.str());
}

void load(string i){
	stringstream s;
	s << "LOAD " << i;
	k++;
	commands.push_back(s.str());
}

void store(string i){
	stringstream s;
	s << "STORE " << i;
	k++;
	commands.push_back(s.str());
}

void copy(string i, string j){
	stringstream s;
	s << "COPY " << i << " " << j;
	k++;
	commands.push_back(s.str());
}

void add(string i, string j){
	stringstream s;
	s << "ADD " << i << " " << j;
	k++;
	commands.push_back(s.str());
}

void sub(string i, string j){
	stringstream s;
	s << "SUB " << i << " " << j;
	k++;
	commands.push_back(s.str());
}

void half(string i){
	stringstream s;
	s << "HALF " << i;
	k++;
	commands.push_back(s.str());
}

void inc(string i){
	stringstream s;
	s << "INC " << i;
	k++;
	commands.push_back(s.str());
}

void dec(string i){
	stringstream s;
	s << "DEC " << i;
	k++;
	commands.push_back(s.str());
}

void jump(int i){
	stringstream s;
	s << "JUMP " << i;
	k++;
	commands.push_back(s.str());
}

void jzero(string i, int j){
	stringstream s;
	s << "JZERO " << i << " " << j;
	k++;
	commands.push_back(s.str());
}

void jodd(string i, int j){
	stringstream s;
	s << "HALF " << i << " " << j;
	k++;
	commands.push_back(s.str());
}

void halt(){
	stringstream s;
	s << "HALT ";
	commands.push_back(s.str());
}

void yyerror(char const *s){
	printf("%s", s);
}

int main()
{
	//printf("ASDF");
	yyparse();
	//printf("fdsa");
	//printf("Przetworzono linii: %d\n",yylineno-1);
	//printf("%lld %lld", variables[0].value, tables[0].table[0]);
	return 0;
}
