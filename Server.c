#include <stdio.h> 
#include <sqlite3.h>
#include <stdlib.h>


int connect_db(void){
sqlite3 *conn;
    sqlite3_stmt *res;
    int error = 0;
    int rec_count = 0;
    const char *errMSG;
    const char *tail;
    error = sqlite3_open("OS.db", &conn);
    if (error) {
        printf("ERROR! Cannot open database");
        exit(0);
    }
    else printf("ok");
    char query[128];
    scanf("%s", query);

    error = sqlite3_exec(conn,
            "update cars set cellid=\'13\' where car_number=10H228",
            0,0,0);
    error = sqlite3_prepare_v2(conn,
            "select car_number, cellid from cars",
            1000, &res, &tail);
    if (error != SQLITE_OK) {
        puts("We did not get any data!");
        exit(0);
    }
    puts("===================================");
    while(sqlite3_step(res) == SQLITE_ROW){
            printf("%s|", sqlite3_column_text(res, 0));
            printf("%s|", sqlite3_column_text(res, 1));
            printf("%s|", sqlite3_column_text(res, 2));
            printf("%s|", sqlite3_column_text(res, 3));

            rec_count++;
    }

    puts("===================================");
    printf("We recieved %d record. \n", rec_count);

    sqlite3_finalize(res);

    sqlite3_close(conn);
}






int main(void){
connect_db();
    
    
}