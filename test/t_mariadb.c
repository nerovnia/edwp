#include <stdio.h>
#include <stdlib.h>
#include "/usr/include/mariadb/mysql.h"

void finish_with_error(MYSQL *conn)
{
  fprintf(stderr, "%s\n", mysql_error(conn));
  mysql_close(conn);
  exit(1);
}

int main (int argc, char* argv[])
{

   /* Initialize Connection */
   MYSQL *conn;
   if (!(conn = mysql_init(0)))
   {
      fprintf(stderr, "unable to initialize connection struct\n");
      exit(1);
   }

   /* Connect to MariaDB Enterprise */
   if (!mysql_real_connect(
         conn,                 /* Connection */
         "0.0.0.0",/* Host */
         "root",            /* User account */
         "example",   /* User password */
         "",               /* Default database */
         3306,                 /* Port number */
         NULL,                 /* Path to socket file */
         0                     /* Additional options */
      ))
   {

      /* Report Error, Close Connection, and Exit if connection fails */
      fprintf(stderr, "Error connecting to Server: %s\n", mysql_error(conn));
      mysql_close(conn);
      exit(1);
   }



  if (mysql_query(conn, "show databases")) {
      finish_with_error(conn);
  }

  MYSQL_RES *result = mysql_store_result(conn);

  if (result == NULL) {
      finish_with_error(conn);
  }

  int num_fields = mysql_num_fields(result);

  MYSQL_ROW row;

  while ((row = mysql_fetch_row(result))) {
      for(int i = 0; i < num_fields; i++) {
          printf("%s ", row[i] ? row[i] : "NULL");
      }

      printf("\n");
  }

  mysql_free_result(result);








   // Close the Connection
   mysql_close(conn);

   return 0;
}