#include "includes/BMSParam.hpp"

BMSParam::~BMSParam() = default;

float Temperature::getValue()
{
  return m_temp;
}

BMSParamType Temperature::getType()
{
  return BMSParamType::TEMP;
}

float SOC::getValue()
{
  return m_soc;
}

BMSParamType SOC::getType()
{
  return BMSParamType::SOC;
}

float ChargeRate::getValue()
{
  return m_cr;
}

BMSParamType ChargeRate::getType()
{
  return BMSParamType::CHARGE_RATE;
}