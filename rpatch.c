#include <stdio.h>
#include <stdlib.h>
#include <librsync.h>

int main(int argc, char *argv[])
{
	FILE *basis_file;
	FILE *delta_file;
	rs_result ret;
	FILE *new_file;
	rs_stats_t stats;

	if(argc != 4)
	{
		fprintf(stderr, "invalid argument(s)\n");
		exit(1);
	}

	basis_file = fopen(argv[1], "rb");
	delta_file = fopen(argv[2], "rb");
	new_file = fopen(argv[3], "wb");

	ret = rs_patch_file(basis_file, delta_file, new_file, &stats);
	fclose(basis_file);
	fclose(delta_file);
	fclose(new_file);
	if(ret != RS_DONE)
	{
		puts(rs_strerror(ret));
		exit(1);
	}
	rs_log_stats(&stats);
	return 0;
}
