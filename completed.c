#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    system("clear");
    int i, jumlah_mahasiswa, menu, cc;
    printf("===============================================================================\n");
    printf("===============================================================================\n");
    printf("===============================================================================\n");
    printf("*******************************************************************************\n");
    printf("*******************************************************************************\n");
    printf("******        ****               ****          ****               ****   ******\n");
    printf("******         *********   **********   *****************   **********   ******\n");
    printf("******   ***    ********   **********   *****************   **********   ******\n");
    printf("******   *  *   ********   **********          **********   **********   ******\n");
    printf("******   ***    ********   **********   *****************   **********   ******\n");
    printf("******         *********   **********   *****************   **********   ******\n");
    printf("******        **********   **********          **********   **********   ******\n");
    printf("*******************************************************************************\n");
    printf("*******************************************************************************\n");
    printf("===============================================================================\n");
    printf("============ APLIKASI PENDATAAN DATA MAHASISWA DAN MATA KULIAH ================\n");
    printf("===============================================================================\n");
    printf("Pilihan Menu :\n");
    printf("1.Pendataan Mahasiswa\n");
    printf("2.Pendataan Matakuliah\n");
    printf("0.Keluar dari Program\n");
    printf("Pilih Menu...\n");
    scanf("%d", &menu);
    if(menu == 1)
    {
        system("clear");
        printf("Masukkan banyak mahasiswa \n");
        scanf("%d", &jumlah_mahasiswa);
        struct
        {
            char nama[255];
            char alamat[255];
            char program_studi[255];
            unsigned int umur;
        }mahasiswa[jumlah_mahasiswa];

        for (i = 0; i < jumlah_mahasiswa; i++)
        {
            printf("DATA KE-%d \n", i+1);
            printf("Masukkan Nama ");
            scanf("%s", &mahasiswa[i].nama);
            printf("Masukkan Alamat ");
            scanf("%s", &mahasiswa[i].alamat);
            printf("Masukkan Prodi ");
            scanf("%s", &mahasiswa[i].program_studi);
            printf("Masukkan Umur ");
            scanf("%d", &mahasiswa[i].umur);
        }
        system("clear");
        printf("------------------------------------------------------------\n");
        printf("| NO |NAMA MAHASISWA|       ALAMAT      |PROGRAM STUDI|UMUR|\n");
        printf("------------------------------------------------------------\n");
        for (i = 0; i < jumlah_mahasiswa; i++)
        {
            printf("| %d  |%-14s|%-19s|%-13s|%-4d|\n", i+1, mahasiswa[i].nama, mahasiswa[i].alamat, mahasiswa[i].program_studi, mahasiswa[i].umur);
        }

        FILE *penunjuk_file;
        penunjuk_file = fopen("data.txt", "w");

        if (penunjuk_file == NULL)
        {
            printf("file tidak ada!!! \n");
            exit(1);
        }
        fputs("------------------------------------------------------------\n", penunjuk_file);
        fputs("| NO |NAMA MAHASISWA|       ALAMAT      |PROGRAM STUDI|UMUR|\n", penunjuk_file);
        fputs("------------------------------------------------------------\n", penunjuk_file);
        for(i = 0; i < jumlah_mahasiswa; i++)
        {
            //char raw_data[255];
            //int data = sprintf(raw_data, "| %d  |%-14s|%-19s|%-13s|%-4d|\n", i+1, mahasiswa[i].nama, mahasiswa[i].alamat, mahasiswa[i].program_studi, mahasiswa[i].umur);
            //fwrite(data, penunjuk_file);
            fprintf(penunjuk_file, "| %d  |%-14s|%-19s|%-13s|%-4d|\n", i+1, mahasiswa[i].nama, mahasiswa[i].alamat, mahasiswa[i].program_studi, mahasiswa[i].umur);
        }
        fputs("------------------------------------------------------------\n", penunjuk_file);
        printf("\nDATA BERHASIL DISIMPAN PADA data.txt");
        fclose(penunjuk_file);
    }
    
    
    else if(menu == 2)//data KRS
    {
        char nama_mahasiswa [255], prodi[30], nim[30];
        int s = 0, j;
        system ("clear");
        printf ("Masukkan Nama Mahasiswa: ");
        scanf ("%s", &nama_mahasiswa[255]);
        printf ("Masukkan Prodi Mahasiswa: ");
        scanf ("%s", &prodi[30]);
        printf ("Masukkan NIM : ");
        scanf ("%s", &nim[30]);
        printf ("Masukkan Total Matkul yang diambil : ");
        scanf ("%d", &cc);
        printf ("\n\n");
        
        struct kredit
        {
            int jumlah;//sks per matkul
            char matkul[100];//nama matkul
            char dosen [300];//nama dosen
            char kelas [5];
        } kredit[cc];

        for (j = 0; j < cc; j++)
            { 
                printf ("Masukkan Nama Matkul %d : ", j+1);
                scanf ("%s", &kredit[j].matkul);
                printf ("Masukkan Kelas : ");
                scanf ("%s", &kredit[j].kelas);
                printf ("Masukkan Jumlah SKS : ");
                scanf ("%d", &kredit[j].jumlah);
                printf ("Masukkan Nama Dosen Pengampu : ");
                scanf ("%s", &kredit[j].dosen);
                printf ("\n");
            }
        
        system("clear");
        printf("Nama   : %-30s\n", &nama_mahasiswa[255]);
        printf("Prodi  : %-30s\n", &prodi[30]);
        printf("NIM    : %-30s\n\n", &nim[30]);
        printf("----------------------------------------------------------------------------------------\n");
        printf("| NO |    NAMA MATKUL    |    JUMLAH SKS    |        DOSEN PENGAMPU        |   KELAS   |\n");
        printf("----------------------------------------------------------------------------------------\n");
        
        for (j = 0; j < cc; j++)
        {
            printf("| %d  |%-19s|%-18d|%-30s|%-11s|\n", j+1, kredit[j].matkul, kredit[j].jumlah, kredit[j].dosen, kredit[j].kelas);
            s = s + kredit[j].jumlah;
        }
        
        printf ("\nTotal SKS = %d", s);

        FILE *penunjuk_file;
        penunjuk_file = fopen("data.txt", "w");

        if (penunjuk_file == NULL)
        {
            printf("file tidak ada!!! \n");
            exit(1);
        }

        fprintf(penunjuk_file, "Nama   : %-30s\n", &nama_mahasiswa[255]);
        fprintf(penunjuk_file, "Prodi  : %-30s\n", &prodi[30]);
        fprintf(penunjuk_file, "NIM    : %-30s\n\n", &nim[30]);
        fputs("----------------------------------------------------------------------------------------\n", penunjuk_file);
        fputs("| NO |    NAMA MATKUL    |    JUMLAH SKS    |        DOSEN PENGAMPU        |   KELAS   |\n", penunjuk_file);
        fputs("----------------------------------------------------------------------------------------\n", penunjuk_file);
        
        for(j = 0; j < cc; j++)
        {
            fprintf(penunjuk_file,"| %d  |%-19s|%-18d|%-30s|%-11s|\n", j+1, kredit[j].matkul, kredit[j].jumlah, kredit[j].dosen, kredit[j].kelas);
        }
        
        fprintf(penunjuk_file, "\nTotal SKS = %d", s);
        fputs("\n------------------------------------------------------------\n", penunjuk_file);
        printf("\nDATA BERHASIL DISIMPAN PADA data.txt");
        fclose(penunjuk_file);
    }
    
    
    else
    {
        exit(0);
    }
    

    return 0;
}
