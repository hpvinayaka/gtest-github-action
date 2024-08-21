#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "TestChallenge.h"

class NetworkAlerterStub {
public:
  MOCK_METHOD(int, networkAlerter, (float celcius));
};

TEST(NetworkAlerterTest, NetworkAlerterSuccessTest) {
  // Arrange
  NetworkAlerterStub stub;
  float celcius = 20.0;
  EXPECT_CALL(stub, networkAlerter(celcius))
 .WillOnce(testing::Return(200));
  // Act
  int result = stub.networkAlerter(celcius);
  // Assert
  ASSERT_EQ(result, 200);
}

TEST(NetworkAlerterTest, NetworkAlerterFailureTest) {
  // Arrange
  NetworkAlerterStub stub;
  float celcius = 21.0;
  EXPECT_CALL(stub, networkAlerter(celcius))
 .WillOnce(testing::Return(500));
  // Act
  int result = stub.networkAlerter(celcius);
  // Assert
  ASSERT_EQ(result, 500);
}

TEST(AlertInCelciusTest, AlertInCelciusTest) {
  // Arrange
  float farenheit = 68.0; // 20 degrees Celsius
  NetworkAlerterStub stub;
  EXPECT_CALL(stub, networkAlerter(testing::_))
 .WillOnce(testing::Return(200));
  // Act
  alertInCelcius(farenheit);
  // Assert
  ASSERT_EQ(alertFailureCount, 0);
}
