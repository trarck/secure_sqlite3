//
//  main.cpp
//  sqlitecrypt
//
//  Created by duanhouhai on 14-3-21.
//  Copyright (c) 2014年 duanhouhai. All rights reserved.
//

#include <iostream>
#include "sqlite3.h"

int main(int argc, const char * argv[])
{

    int result=0;
    
//    sqlite3 *db=NULL;
//    
//    result=sqlite3_open("test.db",&db);
//    result=sqlite3_key(db,"abcd",3); //使用密码，第一次为设置密码
//    //result=sqlite3_rekey(db,NULL,0); //清空密码
//    result=sqlite3_exec(db,"PRAGMA synchronous = OFF",0,0,0);    //提高性能
//    result=sqlite3_exec(db,"PRAGMA cache_size = 8000",0,0,0); //加大缓存
//    result=sqlite3_exec(db,"PRAGMA count_changes = 1",0,0,0); //返回改变记录数
//    result=sqlite3_exec(db,"PRAGMA case_sensitive_like = 1",0,0,0); //支持中文LIKE查询
//    
//    result=sqlite3_exec(db,"CREATE TABLE [MyTable] ([ID] INTEGER PRIMARY KEY NOT NULL,[MyText] TEXT NULL)",0,0,0);
//    result=sqlite3_exec(db,"INSERT INTO MyTable (MyText) VALUES ('测试!')",0,0,0);
//    
//    result=sqlite3_close(db);
    
    
    sqlite3 *database = NULL;
    sqlite3_open("test.db", &database);
    
    result=sqlite3_key(database,"abcd",4);
    
//    result=sqlite3_rekey(database,"abcd",4);
    
    printf("set key result:%d\n",result);
    
    char sql[100];
    sprintf(sql, "select * from %s", "MyTable");
    sqlite3_stmt *statement;
    int res = sqlite3_prepare_v2(database, sql, -1, &statement, NULL);
    
    printf("sqlite3_prepare_v2 result:%d\n",res);
    
    int column_count = sqlite3_column_count(statement);
    printf("select %d columns:\n", column_count);
    int i;
    for (i = 0; i < column_count; ++i) {
        printf("%s\t", sqlite3_column_name(statement, i));
    }
    printf("\n");
    while (sqlite3_step(statement) == SQLITE_ROW) {
        for (i = 0; i < column_count; ++i) {
            printf("%s\t", sqlite3_column_text(statement, i));
        }
        printf("\n");
    }
    char* error;
    sqlite3_exec(database, sql, NULL, NULL, &error);
    
    sqlite3_close(database);
    database = NULL;
    
    
    return 0;
}

