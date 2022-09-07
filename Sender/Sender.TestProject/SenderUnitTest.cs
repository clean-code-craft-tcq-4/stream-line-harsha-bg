using NUnit.Framework;
using System.Collections.Generic;
using System.Linq;

namespace Sender.TestProject
{
    public class Tests
    {
        [Test]
        public void GenerateTemperatureValues()
        {
            List<int> values = BatteryParameterMethods.GenerateTemperatureValues(0,45);
            Assert.IsTrue(values.All(x => x < 45 && x > 0));
        }

        [Test]
        public void GenerateChargeRateValues()
        {
            List<float> values = BatteryParameterMethods.GenerateChargeRateValues(1, 2.5f);
            Assert.IsTrue(values.All(x => x < 2.5 && x > 1));
        }
    }
}