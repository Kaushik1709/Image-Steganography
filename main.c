#include <stdio.h>
#include "encode.h"
#include "decode.h"
#include "types.h"

int main(int argc,char *argv[])
{
    EncodeInfo encInfo;
    DecodeInfo decInfo;
    uint img_size;   
    if(argc<3)
    {
        fprintf(stderr, " ERROR:\n");
        fprintf(stderr, "   To encode : %s -e <input.bmp> <secret.txt> [optional output.bmp]\n", argv[0]);
        fprintf(stderr, "   To decode : %s -d <stego_image.bmp> [optional output_file]\n", argv[0]);
        return 1;
    }
    if(check_operation_type(argv)==e_encode)
    {
        if(argc >=4 && argc <=5)
        {
            printf("Encoding.................\n");
            if(read_and_validate_encode_args(argv,&encInfo)==e_success)
            {
                printf("validated succesfully\n");
                if(do_encoding(&encInfo)==e_success)
                {
                    printf("Congratulations!!! Encoded successfully\n");
                }
                else
                {
                    printf("Sorry encoding was not possible\n");
                }
            }
            else
            {
                fprintf(stderr,"Validation Failed\n");
            }
        }
        else
        {
            fprintf(stderr, "ERROR: Invalid number of arguments for encoding\n");
            fprintf(stderr, "Usage: %s -e <input.bmp> <secret.txt|.c|.sh> [optional output.bmp]\n", argv[0]);
        }
        
    }
    else if(check_operation_type(argv)==e_decode)
    {
        if(argc >= 3 && argc <=4)
        {
            printf("Decoding...........\n");  
            if(read_and_validate_decode_args(argv,&decInfo)==d_success)
            {
                printf("File Validate successfully\n");
                if(do_decoding(&decInfo)==d_success)
                {
                    printf("Congo!!, Decoded successfully.\n");
                }
                else
                {
                    fprintf(stderr,"Decoding failed\n");
                    return d_failure;
                }
            }
            else
            {
                fprintf(stderr,"Validation Failed\n");
                return d_failure;
            }
        }
        
        
        
    }
    else
        {
            fprintf(stderr, "ERROR: Invalid number of arguments for encoding\n");
            fprintf(stderr, "Usage: %s -d <input.bmp> <secret.txt|.c|.sh> [optional output.bmp]\n", argv[0]);
        }

    return 0;
}
