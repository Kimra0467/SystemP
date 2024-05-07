#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

char type(mode_t);
char *perm(mode_t);
void printStat(char*, char*, struct stat*);

int main(int argc, char **argv)
{
    DIR *dp;
    char *dir;
    struct stat st;
    struct dirent *d;
    char path[BUFSIZ+1];
    
    if (argc == 1)
        dir = ".";
    else 
        dir = argv[1];

    if((dp = opendir(dir)) == NULL) {
        perror("opendir");
        exit(1);
    }

    while ((d = readdir(dp)) != NULL) {
        snprintf(path, sizeof(path), "%s/%s", dir, d->d_name);
        if (lstat(path, &st) < 0) {
            perror(path);
            continue;
        }
        printStat(path, d->d_name, &st);
    }

    closedir(dp);
    return 0;
}

void printStat(char *pathname, char *file, struct stat *st) {
    printf("%5lld ", (long long)st->st_blocks);
    printf("%c%s ", type(st->st_mode), perm(st->st_mode));
    printf("%3d ", (int)st->st_nlink);
    printf("%s %s ", getpwuid(st->st_uid)->pw_name, getgrgid(st->st_gid)->gr_name);
    printf("%9lld ", (long long)st->st_size);
    printf("%.12s ", ctime(&st->st_mtime)+4);
    printf("%s\n", file);
}

char type(mode_t mode) {
    if (S_ISREG(mode)) return '-';
    if (S_ISDIR(mode)) return 'd';
    if (S_ISCHR(mode)) return 'c';
    if (S_ISBLK(mode)) return 'b';
    if (S_ISLNK(mode)) return 'l';
    if (S_ISFIFO(mode)) return 'p';
    if (S_ISSOCK(mode)) return 's';
    return '?';
}

char* perm(mode_t mode) {
    static char perms[] = "rwxrwxrwx";
    static char perm[10];
    int i;

    for (i = 0; i < 9; ++i) {
        perm[i] = (mode & (1 << (8-i))) ? perms[i] : '-';
    }

    perm[9] = '\0';

    return perm;
}

