//
//  UWCommonAlert.h
//  UcfWallet
//
//  Created by zsc on 15/7/27.
//  Copyright (c) 2015年 Evan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef enum ItemType
{
    ITEM_OK,
    ITEM_CANCEL,
    ITEM_OTHER
    
}ItemType;

typedef enum StyleType
{
    STYLE_ALERT,
    STYLE_ACTION_SHEET
}StyleType;


@class UWAlertItem;
typedef void(^UWAlertHandler)(UWAlertItem *item);

@interface UWCommonAlert : NSObject
@property(nonatomic,readonly) NSArray *actions;
- (NSString *)buttonTitleAtIndex:(NSInteger)buttonIndex;
- (NSInteger)addButtonWithTitle:(NSString *)title;
- (id)initWithTitle:(NSString *)title andMessage:(NSString *)message style:(StyleType)style;
- (void)addButton:(ItemType)type withTitle:(NSString *)title handler:(UWAlertHandler)handler;
+ (void)showMessage:(NSString *)title message:(NSString *)message;
-(void)show;
@end


@interface UWAlertItem : NSObject
@property (nonatomic, copy) NSString *title;
@property (nonatomic) ItemType type;
@property (nonatomic) NSUInteger tag;
@property (nonatomic, copy) UWAlertHandler action;
@end
