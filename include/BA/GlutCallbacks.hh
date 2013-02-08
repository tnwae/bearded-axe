#ifndef _BA_GLUTCALLBACKS_HH
#define _BA_GLUTCALLBACKS_HH

namespace BA {
  void glutCbkDisplay(void);
  void glutCbkKeyboard(uchar, int, int);
  void glutCbkSpecialKeys(int, int, int);
  void glutCbkMouse(int, int, int, int);
  void glutCbkIdle(void);
  void glutCbkReshape(int, int);
}

#endif
