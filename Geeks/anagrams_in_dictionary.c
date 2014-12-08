#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define COUNTOF(a) (sizeof (a)/ sizeof (a)[0])

typedef unsigned long long HashVal;
HashVal hashmem (char *str, size_t len);

unsigned char primes26[] =
{
5,71,79,19,2,83,31,43,11,53,37,23,41,3,13,73,101,17,29,7,59,47,61,97,89,67,
};

struct anahash {
        struct anahash *next;
        unsigned freq;
        HashVal hash;
        char word[1];
        };

struct anahash *hashtab[1024*1024] = {NULL,};
struct anahash *new_word(char *str, size_t len);
struct anahash **hash_find(struct anahash *wp);

/*********************************************/

HashVal hashmem (char *str, size_t len)
{
size_t idx;
HashVal val=1;

if (!len) return 0;
for (idx = 0; idx < len; idx++) {
        char ch = str[idx];
        if (ch >= 'A' && ch <= 'Z' ) val *= primes26[ ch - 'A'];
        else if (ch >= 'a' && ch <= 'z' ) val *= primes26[ ch - 'a'];
        else continue;
        }
return val;
}

struct anahash *new_word(char *str, size_t len)
{
struct anahash *wp;
if (!len) len = strlen(str);

wp = malloc(len + sizeof *wp );
wp->hash = hashmem(str, len);
wp->next = NULL;
wp->freq = 0;
memcpy (wp->word, str, len);
wp->word[len] = 0;
return wp;
}

struct anahash **hash_find(struct anahash *wp)
{
unsigned slot;
struct anahash **pp;

slot = wp->hash % COUNTOF(hashtab);

for (pp = &hashtab[slot]; *pp; pp= &(*pp)->next) {
        if ((*pp)->hash < wp->hash) continue;
        if (strcmp( wp->word, (*pp)->word ) > 0) continue;
        break;
        }
return pp;
}

char buff [16*4096];
int main (void)
{
size_t pos,end;
struct anahash *wp, **pp;
HashVal val;

memset(hashtab, 0, sizeof hashtab);

while (fgets(buff, sizeof buff, stdin)) {
        for (pos=0; pos < sizeof buff && buff[pos]; ) {
                for(end = pos; end < sizeof buff && buff[end]; end++ ) {
                        if (buff[end] < 'A' || buff[end] > 'z') break;
                        if (buff[end] > 'Z' && buff[end] < 'a') break;
                        }
                if (end > pos) {
                        wp = new_word(buff+pos, end-pos);
                        if (!wp) {pos=end; continue; }
                        pp = hash_find(wp);
                        if (!*pp) *pp = wp;
                        else if ((*pp)->hash == wp->hash
                         && !strcmp((*pp)->word , wp->word)) free(wp);
                        else { wp->next = *pp; *pp = wp; }
                        (*pp)->freq +=1;
                        }
                pos = end;
                for(end = pos; end < sizeof buff && buff[end]; end++ ) {
                        if (buff[end] >= 'A' && buff[end] <= 'Z') break;
                        if (buff[end] >= 'z' && buff[end] <= 'a') break;
                        }
                pos = end;
                }
        }
for (pos = 0;  pos < COUNTOF(hashtab); pos++) {
        if (! &hashtab[pos] ) continue;

        for (pp = &hashtab[pos]; wp = *pp; pp = &wp->next) {
                if (val != wp->hash) {
                        fprintf (stdout, "\nSlot:%u:\n", pos );
                        val = wp->hash;
                        }
                fprintf (stdout, "\t%llx:%u:%s\n", wp->hash, wp->freq, wp->word);
                }
        }

return 0;
}
