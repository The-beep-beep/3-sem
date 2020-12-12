#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

const int lng = 256;
int check = 0;

int Is_Points(char* name) {

	if (name[0] == '.' && ((name[1] == '.' && name[2] == '\0') || name[1] == '\0'))
		return 1;

	return 0;
}

int Descent(char* path, int rec, char* end) {

	DIR* cur = opendir(path);

	if (!cur) return errno;

	struct dirent* content;
	struct stat info;
    while ((content = readdir(cur))) {
    if (rec == 0) continue;
		
		if (Is_Points(content->d_name)) continue;

		char path_full_name[lng];
		strcpy(path_full_name, path);
		strcat(path_full_name, "/");
		strcat(path_full_name, content->d_name);

		char end_maybe[lng];
		strcpy(end_maybe, path);
		strcat(end_maybe, "/");
		strcat(end_maybe, end);

		stat(path_full_name, &info);

		if (S_ISDIR(info.st_mode)) {
			Descent(path_full_name, rec - 1, end);
		}
		else if (strncmp(path_full_name, end_maybe, lng) == 0) {
			printf("Вот тут файл: \n%s\n", path_full_name);
			check++;
		}
	}
}

int main(int argc, char* argv[]) {
	
	char path[lng];
	char end[lng];

	strcpy(path, argv[1]);
	int rec = atoi(argv[2]);
	strcpy(end, argv[3]);

	strcat(path, "/");

	Descent(path, rec, end);

	if (check == 0) printf("Нет такого файла\n");

	return 0;
}
