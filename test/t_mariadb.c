#include <stdio.h>
#include <stdlib.h>
#include "/usr/include/mariadb/mysql.h"

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
         "localhost",/* Host */
         "root",            /* User account */
         "example",   /* User password */
         "webusers",               /* Default database */
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

   // Use the Connection
   // ...

   // Close the Connection
   mysql_close(conn);

   return 0;
}