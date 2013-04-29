#include <stdio.h>
#include <stdlib.h>
#include <librsync.h>

int main(int argc, char *argv[])
{
	FILE *basis_file;
	FILE *sig_file;
	size_t block_len = RS_DEFAULT_BLOCK_LEN;
	size_t strong_len = RS_DEFAULT_STRONG_LEN;
	rs_result ret;
	rs_stats_t stats;

	if(argc != 3)
	{
		fprintf(stderr, "invalid argument(s)\n");
		exit(1);
	}
	basis_file = fopen(argv[1], "rb");
	sig_file = fopen(argv[2], "wb");
	ret = rs_sig_file(basis_file, sig_file, block_len, strong_len, &stats);
	fclose(basis_file);
	fclose(sig_file);
	if(ret)
		puts(rs_strerror(ret));
	else
		rs_log_stats(&stats);
	return 0;
}
