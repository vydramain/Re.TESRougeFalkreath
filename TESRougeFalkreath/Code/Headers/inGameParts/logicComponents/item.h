#ifndef TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_LOGICCOMPONENTS_ITEM_H_
#define TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_LOGICCOMPONENTS_ITEM_H_

class item {
 protected:
  unsigned itemX_;
  unsigned itemY_;
  bool itemConditionInventory_;

 public:
  item() {
    itemConditionInventory_ = true;
  }

  item(unsigned X, unsigned Y) {
    itemConditionInventory_ = false;

    itemX_ = X;
    itemY_ = Y;
  }

  ~item() {}
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_LOGICCOMPONENTS_ITEM_H_
