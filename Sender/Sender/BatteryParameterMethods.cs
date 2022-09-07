using System;
using System.Collections.Generic;

namespace Sender
{
    public class BatteryParameterMethods 
    {
        static Random random = new Random();
        public static List<float> GenerateChargeRateValues(float minChargeRate, float maxChargeRate)
        {
            List<float> chargedValues = new List<float>();
            for(int i = 0;i< 50;i++)
                chargedValues.Add(((float)random.NextDouble() * (maxChargeRate - minChargeRate) + minChargeRate));
            return chargedValues;
        }

        public static List<int> GenerateTemperatureValues(int minTemp, int maxTemp)
        {
            List<int> temperatureValues = new List<int>();
            for (int i = 0; i < 50; i++)
                temperatureValues.Add(random.Next(minTemp,  maxTemp));
            return temperatureValues;
        }

    }
    public class BmsParameter
    {
        public int temperature;
        public float Chargerate;
    }
}
