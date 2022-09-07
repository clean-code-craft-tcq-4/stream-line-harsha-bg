using Sender;
using System.Collections.Generic;

namespace SenderConsoleApp
{
    internal class Program
    {
        static void Main(string[] args)
        {
            List<BmsParameter> container = new List<BmsParameter>();
            List<int> tempValues = BatteryParameterMethods.GenerateTemperatureValues(1, 45);
            List<float> ChargeRatevalues = BatteryParameterMethods.GenerateChargeRateValues(1, 2.5f);
            for (int i = 0; i < tempValues.Count; i++)
            {
                BmsParameter bms = new BmsParameter();
                bms.temperature = tempValues[i];
                bms.Chargerate = ChargeRatevalues[i];
                container.Add(bms);
            }
            Utilities.PrintbmsValues(container);
        }
    }
}
