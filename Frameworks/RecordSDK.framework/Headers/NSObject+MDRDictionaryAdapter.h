//
//  NSObject+MDRDictionaryAdapter.h
//  MomoChat
//
//  Created by Latermoon on 12-9-16.
//  Copyright (c) 2012年 wemomo.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <libkern/OSAtomic.h>
/**
 * 实现了MFDictionaryAccessor协议的类可使用下列方法
 */
@interface NSObject (MDRDictionaryAdapter)

#pragma mark - Wrap for objectForKey:aKey
- (id)mdr_objectForKey:(NSString *)aKey defaultValue:(id)value;
- (NSString *)mdr_stringForKey:(NSString *)aKey defaultValue:(NSString *)value;
- (NSArray *)mdr_arrayForKey:(NSString *)aKey defaultValue:(NSArray *)value;
- (NSDictionary *)mdr_dictionaryForKey:(NSString *)aKey defaultValue:(NSDictionary *)value;
- (NSData *)mdr_dataForKey:(NSString *)aKey defaultValue:(NSData *)value;
- (NSUInteger)mdr_unsignedIntegerForKey:(NSString *)aKey defaultValue:(NSUInteger)value;
- (NSInteger)mdr_integerForKey:(NSString *)aKey defaultValue:(NSInteger)value;
- (float)mdr_floatForKey:(NSString *)aKey defaultValue:(float)value;
- (double)mdr_doubleForKey:(NSString *)aKey defaultValue:(double)value;
- (long long)mdr_longLongValueForKey:(NSString *)aKey defaultValue:(long long)value;
- (BOOL)mdr_boolForKey:(NSString *)aKey defaultValue:(BOOL)value;
- (NSDate *)mdr_dateForKey:(NSString *)aKey defaultValue:(NSDate *)value;
- (NSNumber *)mdr_numberForKey:(NSString *)aKey defaultValue:(NSNumber *)value;
- (id)mdr_objectforKeyThreadSafety:(id)key lock:(OSSpinLock)lock defaultValue:(id)value;
- (int)mdr_intForKey:(NSString *)aKey defaultValue:(int)value;

#pragma mark - Wrap for setObject:value forKey:aKey
- (void)mdr_setObjectSafe:(id)value forKey:(id)aKey;
- (void)mdr_setString:(NSString *)value forKey:(NSString *)aKey;
- (void)mdr_setNumber:(NSNumber *)value forKey:(NSString *)aKey;
- (void)mdr_setInteger:(NSInteger)value forKey:(NSString *)aKey;
- (void)mdr_setInt:(int)value forKey:(NSString *)aKey;
- (void)mdr_setFloat:(float)value forKey:(NSString *)aKey;
- (void)mdr_setDouble:(double)value forKey:(NSString *)aKey;
- (void)mdr_setLongLongValue:(long long)value forKey:(NSString *)aKey;
- (void)mdr_setBool:(BOOL)value forKey:(NSString *)aKey;
- (void)mdr_setObjectThreadSafety:(id)value forKey:(id)key lock:(OSSpinLock)lock;
- (void)mdr_removeAllObjectThreadSafety:(OSSpinLock)lock;
- (void)mdr_removeObjectThreadSafetyForKey:(id)key lock:(OSSpinLock)lock;
- (void)mdr_removeObjectsThreadSafetyForKeys:(NSArray *)keys lock:(OSSpinLock)lock;

@end
