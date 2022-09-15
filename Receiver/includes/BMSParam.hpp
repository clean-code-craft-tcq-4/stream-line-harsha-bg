#ifndef BMS_PARAM_HPP_
#define BMS_PARAM_HPP_

#include <iostream>
#include <vector>

#define EARLY_WARNING_PERCENTAGE 5 

using namespace std;
enum BMSParamType
{
    TEMP = 0,
    SOC,
    CHARGE_RATE
};
class BMSParam
{
    public:
    virtual float getValue() = 0;
    virtual BMSParamType getType() = 0;
    BMSParam() = default;
    virtual ~BMSParam();
};

class Temperature : public BMSParam
{
    public:
    explicit Temperature(float temp): m_temp(temp){}
    float getValue() override;
    BMSParamType getType() override;
    private:
    const float MIN_TEMP {0};
    const float MAX_TEMP {45};
    float m_temp {0.0};
};

class SOC : public BMSParam
{
    public:
    explicit SOC(float soc): m_soc(soc){}
    float getValue() override;
    BMSParamType getType() override;
    private:
    const float MIN_SOC {20};
    const float MAX_SOC {80};
    float m_soc {0.0};
};

class ChargeRate : public BMSParam
{
    public:
    explicit ChargeRate(float cr): m_cr(cr){}
    float getValue() override;
    BMSParamType getType() override;
    private:
    const float MIN_CHARGE_RATE {0};
    const float MAX_CHARGE_RATE {.8};
    float m_cr{0.0};
};

#endif