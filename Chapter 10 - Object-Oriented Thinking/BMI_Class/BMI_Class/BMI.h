//
//  BMI.h
//  BMI_Class
//
//  Created by Brandon Kamplain on 2/13/22.
//

#ifndef BMI_h
#define BMI_h

#include <string>
//using namespace std;

class BMI
{
public:
    BMI(const std::string& newName, int newAge, double newWeight, double newHeight);
    BMI(const std::string& newName, double newWeight, double newHeight);
    
    double getBMI() const;
    
    std::string getStatus() const;
    
    std::string getName() const;
    void setName(const std::string& newName);
    
private:
    std::string name;
    int age;
    double weight;
    double height;
};

#endif /* BMI_h */
