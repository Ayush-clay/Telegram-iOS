//
//  ASLayoutOptions.h
//  AsyncDisplayKit
//
//  Created by Ricky Cancro on 8/27/15.
//  Copyright (c) 2015 Facebook. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol ASLayoutable;

#import <AsyncDisplayKit/ASBaselineLayoutable.h>
#import <AsyncDisplayKit/ASStackLayoutable.h>
#import <AsyncDisplayKit/ASStaticLayoutable.h>

@interface ASLayoutOptions : NSObject <ASBaselineLayoutable, ASStackLayoutable, ASStaticLayoutable, NSCopying>

- (instancetype)initWithLayoutable:(id<ASLayoutable>)layoutable;
- (void)setValuesFromLayoutable:(id<ASLayoutable>)layoutable;

@property (nonatomic, assign) BOOL isMutable;

#if DEBUG
@property (nonatomic, assign) NSUInteger changeMonitor;
#endif

#pragma mark - ASStackLayoutable

@property (nonatomic, readwrite) CGFloat spacingBefore;
@property (nonatomic, readwrite) CGFloat spacingAfter;
@property (nonatomic, readwrite) BOOL flexGrow;
@property (nonatomic, readwrite) BOOL flexShrink;
@property (nonatomic, readwrite) ASRelativeDimension flexBasis;
@property (nonatomic, readwrite) ASStackLayoutAlignSelf alignSelf;

#pragma mark - ASBaselineLayoutable

@property (nonatomic, readwrite) CGFloat ascender;
@property (nonatomic, readwrite) CGFloat descender;

#pragma mark - ASStaticLayoutable

@property (nonatomic, readwrite) ASRelativeSizeRange sizeRange;
@property (nonatomic, readwrite) CGPoint position;

- (void)setupDefaults;

@end
