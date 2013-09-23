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

@interface UIGlossyButton : UIButton

// to prevent name collision after iOS7, tintColor -> buttonTintColor
@property (nonatomic, strong) UIColor *buttonTintColor UI_APPEARANCE_SELECTOR;  // button background tint color
@property (nonatomic, strong) UIColor *disabledColor UI_APPEARANCE_SELECTOR;   // color when disabled, can be nil for lightgray color when disabled
@property (nonatomic, assign) CGFloat buttonCornerRadius UI_APPEARANCE_SELECTOR;	// outer button border
@property (nonatomic, assign) UIEdgeInsets buttonInsets UI_APPEARANCE_SELECTOR;     // inset of the button face, default 0.0
@property (nonatomic, strong) UIColor *borderColor UI_APPEARANCE_SELECTOR;	// button border color, default nil = dark gray
@property (nonatomic, strong) UIColor *disabledBorderColor UI_APPEARANCE_SELECTOR;   // color when disabled, can be nil for lightgray color when disabled
@property (nonatomic, assign) CGFloat buttonBorderWidth UI_APPEARANCE_SELECTOR; //  outer button border width, default 1.0
@property (nonatomic, assign) CGFloat innerBorderWidth UI_APPEARANCE_SELECTOR;	 // inner stroke that fill same color as the tint color, default = 1.0
@property (nonatomic, assign) UIGlossyButtonStrokeType strokeType UI_APPEARANCE_SELECTOR;	// outer button border
@property (nonatomic, assign) UIGlossyButtonExtraShadingType extraShadingType UI_APPEARANCE_SELECTOR;	// extra shading effect other than gradient
@property (nonatomic, assign) BOOL invertGraidentOnSelected UI_APPEARANCE_SELECTOR;    // invert the gradient when button down for inner bevel effect, default = NO
@property (nonatomic, assign) CGFloat backgroundOpacity UI_APPEARANCE_SELECTOR; // default 1.0, set smaller to draw button in transparent

/* path for the button, default is a round corner rectangle, we can subclass and customize it */
- (UIBezierPath *) pathForButton : (CGFloat) inset;

- (void) setGradientType : (UIGlossyButtonGradientType) type;

- (void) setActionSheetButtonWithColor : (UIColor*) color;
- (void) setNavigationButtonWithColor : (UIColor*) color;	// navigation bar button, or store button

@end


/* subtype that with left and right navigation button shape */
@interface UIGNavigationButton : UIGlossyButton

@property (nonatomic, getter = isLeftArrow) BOOL leftArrow;

@end

@interface UIGBadgeButton : UIGlossyButton

@property (nonatomic, assign) NSInteger numberOfEdges;
@property (nonatomic, assign) CGFloat innerRadiusRatio;

@end