
@protocol ALPickerViewDelegate;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


@interface ALPickerView : UIView <UITableViewDataSource, UITableViewDelegate> {
@private
  UITableView *internalTableView_;
}

// Set a delegate conforming to ALPickerViewDelegate protocol
@property (nonatomic, assign) id<ALPickerViewDelegate> delegate;
// If set to nil the all option row is hidden at all, default is 'All'
@property (nonatomic, strong) NSString *allOptionTitle;

@property (nonatomic, strong) id<ALPickerViewDelegate> pickerViewDelegate;


// Reload whole pickerview from delegate
- (void)reloadAllComponents;

@end


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


@protocol ALPickerViewDelegate <NSObject>

// Return the number of elements of your pickerview
- (NSInteger)numberOfRowsForPickerView:(ALPickerView *)pickerView;
// Return a plain UIString to display on the given row
- (NSString *)pickerView:(ALPickerView *)pickerView textForRow:(NSInteger)row;
// Return a boolean selection state on the given row
- (BOOL)pickerView:(ALPickerView *)pickerView selectionStateForRow:(NSInteger)row;

@optional

// Inform the delegate that a row got selected, if row = -1 all rows are selected
- (void)pickerView:(ALPickerView *)pickerView didCheckRow:(NSInteger)row;
// Inform the delegate that a row got deselected, if row = -1 all rows are deselected
- (void)pickerView:(ALPickerView *)pickerView didUncheckRow:(NSInteger)row;

@end
