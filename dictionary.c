// Implements a dictionary's functionality

#include <stdbool.h>
//#include <stdint.h>
#include "dictionary.h"

unsigned long int count=0;
unsigned long int si=0;
trie* nodeAddr[400000] ;
char buffer[LENGTH+1];


trie* root=NULL;


trie* newNode(){


    trie* ne = (trie*) calloc(sizeof(trie),1);

    if(ne != NULL){

       nodeAddr[count++]=ne;
        ne->isEndOfWord = false;

        for(int i = 0; i < SIZE; i++)
            ne->children[i] = NULL;
    }

    return ne;
}

void insert( const char *key)
{
    int level;
    int length = strlen(key);
    int index;

    struct trie *pCrawl = root;

    for (level = 0; level < length; level++)
    {
        if((int)key[level]!=39)
        index = hash(key[level]);
        else index=26;
        if (!pCrawl->children[index])
            pCrawl->children[index] = newNode();

        pCrawl = pCrawl->children[index];

    }

    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}

// Returns true if word is in dictionary else false
bool check( const char *key)
{
    int level;
    int length = strlen(key);
    int index;
    struct trie *pCrawl = root;

    for (level = 0; level < length; level++)
    {

         if((int)key[level]!=39)
         index = hash(key[level]);
        else index=26;
        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];

}
    return (pCrawl != NULL && pCrawl->isEndOfWord);


}



// Loads dictionary into memory, returning true if successful else false
bool load( const char *dictionary)
{
    int i=0;
 root=newNode();


 FILE *filePtr=fopen(dictionary,"r");
 char temp='\0';
 while (temp!=EOF)
    {
	temp=fgetc(filePtr);

	 if(temp=='\n') {
		buffer[i]='\0';

    insert((const char*)buffer);

	i=0;
	si++;
	}
	else{

		buffer[i]=temp;
		i++;
	}



    }
    fclose(filePtr);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{

    unsigned int i;
    i=si;
    return i;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    unsigned int i;
    for (i=0;i<count;i++)
    free(nodeAddr[i]);
    return true;
}
