#include <stdio.h>
#include <stdlib.h>
#include <librsync.h>

int main(int argc, char *argv[])
{
	FILE *sig_file;
	FILE *new_file;
	FILE *delta_file;
	rs_result ret;
	rs_signature_t *sumset;
	rs_stats_t stats;

	if(argc != 4)
	{
		fprintf(stderr, "invalid argument(s)\n");
		exit(1);
	}

	sig_file = fopen(argv[1], "rb");
	new_file = fopen(argv[2], "rb");
	delta_file = fopen(argv[3], "wb");

	ret = rs_loadsig_file(sig_file, &sumset, &stats);
	if(ret != RS_DONE)
	{
		puts(rs_strerror(ret));
		exit(1);
	}
	rs_log_stats(&stats);

	if(rs_build_hash_table(sumset) != RS_DONE)
	{
		puts(rs_strerror(ret));
		exit(1);
	}

	if(rs_delta_file(sumset, new_file, delta_file, &stats) != RS_DONE)
	{
		puts(rs_strerror(ret));
		exit(1);
	}
	rs_log_stats(&stats);

	rs_free_sumset(sumset);
	fclose(sig_file);
	fclose(new_file);
	fclose(delta_file);
	return 0;
}
