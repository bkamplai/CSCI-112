//
//  NonPositiveSideException.h
//  CustomExceptions
//
//  Created by Brandon Kamplain on 4/3/22.
//

#ifndef NonPositiveSideException_h
#define NonPositiveSideException_h
#include <stdexcept>
using namespace std;

class NonPositiveSideException: public logic_error
{
public:
  NonPositiveSideException(double side)
    : logic_error("Non-positive side")
  {
    this->side = side;
  }

  double getSide()
  {
    return side;
  }

private:
  double side;
};

#endif /* NonPositiveSideException_h */
