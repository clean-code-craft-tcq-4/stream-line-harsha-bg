#ifndef BMS_PARAM_HPP_
#define BMS_PARAM_HPP_

#include <iostream>
#include <vector>

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
    float m_temp {0.0};
};

class SOC : public BMSParam
{
    public:
    explicit SOC(float soc): m_soc(soc){}
    float getValue() override;
    BMSParamType getType() override;
    private:
    float m_soc {0.0};
};

class ChargeRate : public BMSParam
{
    public:
    explicit ChargeRate(float cr): m_cr(cr){}
    float getValue() override;
    BMSParamType getType() override;
    private:
    float m_cr{0.0};
};

#endif