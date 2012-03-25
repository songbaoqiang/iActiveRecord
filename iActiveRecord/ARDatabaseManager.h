//
//  ARDatabaseManager.m
//  iActiveRecord
//
//  Created by Alex Denisov on 10.01.12.
//  Copyright (c) 2012 CoreInvader. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <sqlite3.h>

@interface ARDatabaseManager : NSObject
{
    @private
    sqlite3 *database;
    NSString *dbPath;
    NSString *dbName;
}

- (void)createDatabase;
- (void)clearDatabase;
- (void)appendMigrations;
- (void)openConnection;
- (void)closeConnection;

- (NSString *)tableName:(NSString *)modelName;
- (NSString *)documentsDirectory;

+ (id)sharedInstance;

- (NSNumber *)insertRecord:(NSString *)aRecordName withSqlQuery:(const char *)anSqlQuery;
- (NSNumber *)getLastId:(NSString *)aRecordName;
- (void)executeSqlQuery:(const char *)anSqlQuery;
- (NSArray *)allRecordsWithName:(NSString *)aName withSql:(NSString *)aSqlRequest;
- (NSInteger)countOfRecordsWithName:(NSString *)aName;
- (NSInteger)functionResult:(NSString *)anSql;

@end
 