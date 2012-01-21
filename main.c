/* Enter your code here. Read input from STDIN. Print output to STDOUT */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define STREET_VALUE	 "street"
#define ROAD_VALUE		 "road"
#define ILLINOIS_VALUE	 "illinois"
#define NEWYORK_VALUE	 "new york"
#define CALIFORNIA_VALUE "california"

#define RECORD_NUMBER	20
#define STRING_LENGTH	50
#define INPUT_LENGTH	2000
#define ZIP_LENGTH		10
#define CC_LENGTH		15

void str_tolower(char *str);
int case_insensitive_cmp(char str1[STRING_LENGTH], char str2[STRING_LENGTH]);
void split_join(char *str, char *pattern);
void plus_split(char* str);
int mail_fraud(char email1[STRING_LENGTH], char email2[STRING_LENGTH]);
void standarize_street(char street[STRING_LENGTH]);
void standarize_states(char state[STRING_LENGTH]);
int same_street(char street1[STRING_LENGTH], char street2[STRING_LENGTH]);
int same_city(char city1[STRING_LENGTH], char city2[STRING_LENGTH]);
int same_state(char state1[STRING_LENGTH], char state2[STRING_LENGTH]);
int same_zip(char zip1[ZIP_LENGTH], char zip2[ZIP_LENGTH]);
int same_cc(char cc1[CC_LENGTH], char cc2[CC_LENGTH]);
int sort_orders(int fraudulent_orders[], int array_size);


int main()
{
    int lines_number = 5;
    
    int read_lines, i, j=0;
	int first_fraud = 1;
    char input[INPUT_LENGTH];
	int fraudulent_orders[RECORD_NUMBER];
    int orders[RECORD_NUMBER];
    int deals[RECORD_NUMBER];
    char emails[RECORD_NUMBER][STRING_LENGTH];
    char streets[RECORD_NUMBER][STRING_LENGTH];
    char cities[RECORD_NUMBER][STRING_LENGTH];
    char states[RECORD_NUMBER][STRING_LENGTH];
    char zips[RECORD_NUMBER][ZIP_LENGTH];
    char credit_cards[RECORD_NUMBER][STRING_LENGTH];
    
	
	orders[0] = 4;
	orders[1] = 3;
	orders[2] = 2;
	orders[3] = 0;
	orders[4] = 1;
	
	deals[0] = 1;
	deals[1] = 1;
	deals[2] = 2;
	deals[3] = 2;
	deals[4] = 3;
	
	strcpy(emails[0] ,"mansou.r+high@hotmail.com");
	strcpy(emails[1] , "Mansour@hotmail.com");
	strcpy(emails[2] , "mansour+.....dibfaisdbcais@hotmaiL.com");
	strcpy(emails[3] , "mansoUR@hotmail.com");
	strcpy(emails[4] , "mansour@hotmail.com");
	
	strcpy(streets[0] ,"123 sesame st.");
	strcpy(streets[1] , "123 SESAME street");
	strcpy(streets[2] , "where are you road");
	strcpy(streets[3] , "where are you rd.");
	strcpy(streets[4] , "mansour@hotmail.com");
	
	strcpy(cities[0] ,"new york");
	strcpy(cities[1] , "new york");
	strcpy(cities[2] , "boston");
	strcpy(cities[3] , "BOSTON");
	strcpy(cities[4] , "mansour@hotmail.com");
	
	strcpy(states[0] ,"new york");
	strcpy(states[1] , "new york");
	strcpy(states[2] , "california");
	strcpy(states[3] , "CA");
	strcpy(states[4] , "mansour@hotmail.com");

	strcpy(zips[0] ,"4011");
	strcpy(zips[1] , "4011");
	strcpy(zips[2] , "6655");
	strcpy(zips[3] , "6655");
	strcpy(zips[4] , "mansour@hotmail.com");
	
	strcpy(credit_cards[0] ,"4011");
	strcpy(credit_cards[1] , "40121");
	strcpy(credit_cards[2] , "66553");
	strcpy(credit_cards[3] , "6655");
	strcpy(credit_cards[4] , "mansour@hotmail.com");

	for (read_lines=0; read_lines < lines_number; read_lines++)
    {
        for (i = read_lines + 1; i < lines_number; i++)
        {
            if (deals[i] != deals[read_lines])
				continue;
			if (mail_fraud(emails[read_lines], emails[i]) && 
				!same_cc(credit_cards[read_lines], credit_cards[i]))
			{
				
				
				fraudulent_orders[j] = orders[read_lines];
                j++;
                fraudulent_orders[j] = orders[i];
                j++;
			}
			else if (same_state(states[read_lines], states[i]) && 
				same_city(cities[read_lines], cities[i]) &&
				same_street(streets[read_lines], streets[i]) &&
				same_zip(zips[read_lines], zips[i]) &&
				!same_cc(credit_cards[read_lines], credit_cards[i]))
			{
				
				
				fraudulent_orders[j] = orders[read_lines];
                j++;
                fraudulent_orders[j] = orders[i];
                j++;
				
			}
			
		}
	}
	sort_orders(fraudulent_orders, j--);
	for(i=0; i <= j; i++)
	{
		printf("%d", fraudulent_orders[i]);
		if (i < j) {
			printf(",");
		}
		
	}
	memset (emails[read_lines],'\0', STRING_LENGTH);
	memset (streets[read_lines],'\0', STRING_LENGTH);
	memset (states[read_lines],'\0', STRING_LENGTH);
	memset (zips[read_lines],'\0', STRING_LENGTH);
	memset (cities[read_lines],'\0', STRING_LENGTH);
	memset (credit_cards[read_lines],'\0', STRING_LENGTH);
    /*gets (input);
    lines_number = atoi(input);
	
    for (read_lines=0; read_lines < lines_number; read_lines++)
    {
        printf("\n---- %d ---\n", read_lines);
        gets ( input);
        
        //printf ("Splitting string \"%s\" into tokens:\n",input);
        splitter = strtok (input,",");
        //while (splitter != NULL)
        //{
		
        printf ("order -- %s\n",splitter);
        orders[read_lines] = atoi(splitter);
        
        splitter = strtok (NULL, ",");
        printf ("deal -- %s\n",splitter);
        deals[read_lines] = atoi(splitter);
        
        splitter = strtok (NULL, ",");
        printf ("email -- %s\n",splitter);
        strcpy(emails[read_lines] ,splitter);
        
        splitter = strtok (NULL, ",");
        printf ("street -- %s\n",splitter);
        strcpy(streets[read_lines] , splitter);
        
        splitter = strtok (NULL, ",");
        printf ("city -- %s\n",splitter);
        strcpy(cities[read_lines] , splitter);
        
        splitter = strtok (NULL, ",");
        //printf ("state -- %s\n",splitter);
        strcpy(states[read_lines] , splitter);
        splitter = strtok (NULL, ",");
        //printf ("zips -- %s\n",splitter);
        strcpy(zips[read_lines] , splitter);
        splitter = strtok (NULL, ",");
        //printf ("street -- %s\n",splitter);
        strcpy(credit_cards[read_lines] , splitter);
        //}
        
        //printf("%s\n", input);
    }*/
    
}

void str_tolower(char *str)
{
	int j=0;
	while (str[j])
	{
		str[j] = tolower(str[j]);
		j++;
	}
}

int case_insensitive_cmp(char str1[STRING_LENGTH], char str2[STRING_LENGTH])
{
	int j=0;
	while (str1[j])
	{
		if (tolower(str1[j]) != tolower(str2[j]))
			return 1;
		j++;
	}
	return 0;
}

void split_join(char *str, char *pattern)
{
	char *splitter;
	
	splitter = strtok(str, pattern);
	while (1) {
		splitter = strtok(NULL, pattern);
		if (splitter == NULL)
			break;
		sprintf(str, "%s%s", str, splitter);
	}
}

void plus_split(char* str)
{
	char *splitter;
	
	splitter = strtok(str, "+");
	splitter = strtok(NULL, "+");
	
	if (splitter!=NULL) {
		splitter = strtok(splitter, "@");
		splitter = strtok(NULL, "@");
	} else {
		splitter = strtok(str, "@");
		splitter = strtok(NULL, "@");
	}
	
	
	sprintf(str, "%s%s", str, splitter);
}

int mail_fraud(char email1[STRING_LENGTH], char email2[STRING_LENGTH])
{	
	if(!strcmp(email1, email2))
		return 1;
	if (!case_insensitive_cmp(email1, email2)) 
		return 1;
	
	plus_split(email1);
	plus_split(email2);
	if (!case_insensitive_cmp(email1, email2)) 
		return 1;
	split_join(email1, ".");
	split_join(email2, ".");
	if (!case_insensitive_cmp(email1, email2)) 
		return 1;
	return 0;
}

void standarize_street(char street[STRING_LENGTH])
{
	char *temp_str;
	
	str_tolower(street);
	temp_str = strstr(street, STREET_VALUE);
	
	if (temp_str!=NULL) 
		strncpy(temp_str, "st.",6);
	temp_str = strstr(street, ROAD_VALUE);
	if (temp_str!=NULL) 
		strncpy(temp_str, "rd.",4);
}

void standarize_states(char state[STRING_LENGTH])
{
	char *temp_str;
	
	str_tolower(state);
	
	temp_str = strstr(state, NEWYORK_VALUE);
	if (temp_str!=NULL) 
		strncpy(temp_str, "ny", 8);
	
	temp_str = strstr(state, ILLINOIS_VALUE);
	if (temp_str!=NULL) 
		strncpy(temp_str, "il",8);
	
	temp_str = strstr(state, CALIFORNIA_VALUE);
	if (temp_str!=NULL) 
		strncpy(temp_str, "ca",10);
}


int same_street(char street1[STRING_LENGTH], char street2[STRING_LENGTH])
{		
	if (!strcmp(street1, street2)) 
		return 1;
	
	standarize_street(street1);
	standarize_street(street2);
	if (!strcmp(street1, street2))
		return 1;
	return 0;
}

int same_city(char city1[STRING_LENGTH], char city2[STRING_LENGTH])
{
	if (!case_insensitive_cmp(city1, city2)) 
		return 1;
	return 0;
}

int same_state(char state1[STRING_LENGTH], char state2[STRING_LENGTH])
{
	if (!strcmp(state1, state2)) 
		return 1;
	
	standarize_states(state1);
	standarize_states(state2);
	if (!strcmp(state1, state2))
		return 1;
	return 0;
}

int same_zip(char zip1[ZIP_LENGTH], char zip2[ZIP_LENGTH])
{
	if (!strcmp(zip1, zip2)) 
		return 1;
	return 0;
}

int same_cc(char cc1[CC_LENGTH], char cc2[CC_LENGTH])
{
	if (!strcmp(cc1, cc2)) 
		return 1;
	return 0;
}

int sort_orders(int fraudulent_orders[], int array_size)
{
	int i, j, min, aux;
	
	for (i = 0; i < array_size; i++) {
		for(j= i+1; j < array_size; j++) {
			min = fraudulent_orders[i];
			if (fraudulent_orders[j] < min) {
				aux = fraudulent_orders[i];
				fraudulent_orders[i] = fraudulent_orders[j];
				fraudulent_orders[j] = aux;
			}
		}
	}
	return 0;
}
