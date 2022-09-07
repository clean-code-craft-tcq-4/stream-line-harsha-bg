using System;
using System.Collections.Generic;

namespace Sender
{
    public class Utilities
    {
        public static void PrintbmsValues(List<BmsParameter> valuesToPrint)
        {
            Console.WriteLine("Temperature\t ChargeRate\n");
            foreach (var value in valuesToPrint)
            {
                Console.WriteLine("{0}\t\t {1}", value.temperature, value.Chargerate);
            }
        }
    }
}
