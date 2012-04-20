//
//  UIButton+Effects.h
//  fwMeCard
//
//  Created by Water Lou on 6/1/11.
//  Copyright 2011 First Water Tech Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UIButton(UIGlossyButton)

- (void) useWhiteLabel : (BOOL) dimOnClickedOrDisabled;
- (void) useBlackLabel : (BOOL) dimOnClickedOrDisabled;

@end

@interface UIColor(UIGlossyButton)

+ (UIColor*) doneButtonColor;
+ (UIColor*) navigationBarButtonColor;

@end

typedef enum _UIGlossyButtonGradientType {
	kUIGlossyButtonGradientTypeLinearSmoothStandard = 0,	// general vertical linear gradient, normal to little dark
	kUIGlossyButtonGradientTypeLinearGlossyStandard,		// iOS like glossy effect
	kUIGlossyButtonGradientTypeLinearSmoothExtreme,         // Very bright to very dim
	kUIGlossyButtonGradientTypeLinearSmoothBrightToNormal,	// very bright to normal
	kUIGlossyButtonGradientTypeSolid,                       // plain solid  
} UIGlossyButtonGradientType;

typedef enum _UIGlossyButtonStrokeType{
    kUIGlossyButtonStrokeTypeNone = 0,
	kUIGlossyButtonStrokeTypeSolid,	// simple solid color
	kUIGlossyButtonStrokeTypeInnerBevelDown, // draw bevel down effect (naivagation bar button)
	kUIGlossyButtonStrokeTypeGradientFrame,	// frame a 1 pixel b/w gradient (default delete button)	
    kUIGlossyButtonStrokeTypeBevelUp,       // stroke bevel using button color
} UIGlossyButtonStrokeType;

typedef enum _UIGlossyButtonExtraShadingType {
	kUIGlossyButtonExtraShadingTypeNone = 0,	// no extra shading
	kUIGlossyButtonExtraShadingTypeRounded,	// rounded shading, shading radius = button corner radius
	kUIGlossyButtonExtraShadingTypeAngleLeft,
	kUIGlossyButtonExtraShadingTypeAngleRight,
} UIGlossyButtonExtraShadingType;

/**
  Create color button without any images,
  draw with different gradient, frame and glossy effect
 **/

@interface UIGlossyButton : UIButton {
@private
	// data to create gradient of the button
	const CGFloat *background_gradient;
	const CGFloat *locations;
	NSInteger numberOfColorsInGradient;
	
@protected
    UIColor *_tintColor;
    UIColor *_disabledColor;
	
    UIColor *_borderColor;
	UIColor *_disabledBorderColor;
	
    CGFloat _buttonCornerRadius;
    CGFloat _innerBorderWidth;
	CGFloat _buttonBorderWidth;
    
    BOOL    _invertGraidentOnSelected;
	
	CGFloat _backgroundOpacity;
    
    UIEdgeInsets _buttonInsets;
	
	UIGlossyButtonStrokeType _strokeType;
	UIGlossyButtonExtraShadingType _extraShadingType;
}

@property (nonatomic, retain) UIColor *tintColor;
@property (nonatomic, retain) UIColor *disabledColor;   // color when disabled, can be nil for lightgray color when disabled
@property (nonatomic, assign) CGFloat buttonCornerRadius;	// outer button border
@property (nonatomic, assign) UIEdgeInsets buttonInsets;     // inset of the button face, default 0.0
@property (nonatomic, retain) UIColor *borderColor;	// button border color, default nil = dark gray
@property (nonatomic, retain) UIColor *disabledBorderColor;   // color when disabled, can be nil for lightgray color when disabled
@property (nonatomic, assign) CGFloat buttonBorderWidth; //  outer button border width, default 1.0
@property (nonatomic, assign) CGFloat innerBorderWidth;	 // inner stroke that fill same color as the tint color, default = 1.0
@property (nonatomic, assign) UIGlossyButtonStrokeType strokeType;	// outer button border
@property (nonatomic, assign) UIGlossyButtonExtraShadingType extraShadingType;	// extra shading effect other than gradient
@property (nonatomic, assign) BOOL invertGraidentOnSelected;    // invert the gradient when button down for inner bevel effect, default = NO
@property (nonatomic, assign) CGFloat backgroundOpacity; // default 1.0, set smaller to draw button in transparent

/* path for the button, default is a round corner rectangle, we can subclass and customize it */
- (UIBezierPath *) pathForButton : (CGFloat) inset;

- (void) setGradientType : (UIGlossyButtonGradientType) type;

- (void) setActionSheetButtonWithColor : (UIColor*) color;
- (void) setNavigationButtonWithColor : (UIColor*) color;	// navigation bar button, or store button

@end


/* subtype that with left and right navigation button shape */
@interface UIGNavigationButton : UIGlossyButton {
@private
	BOOL _leftArrow;
}

@property (nonatomic, getter = isLeftArrow) BOOL leftArrow;

@end

@interface UIGBadgeButton : UIGlossyButton {
@private
    NSInteger numberOfEdges;
	CGFloat innerRadiusRatio;
}

@property (nonatomic, assign) NSInteger numberOfEdges;
@property (nonatomic, assign) CGFloat innerRadiusRatio;

@end