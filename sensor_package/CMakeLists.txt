cmake_minimum_required(VERSION 3.8)
project(sensor_package)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

if(BUILD_TESTING)
find_package(ament_lint_auto REQUIRED)

set(ament_cmake_copyright_FOUND TRUE)

set(ament_cmake_cpplint_FOUND TRUE)
ament_lint_auto_find_test_dependencies()
endif()

add_executable(speed_controller src/speed_controller.cpp)
ament_target_dependencies(speed_controller rclcpp std_msgs)

install(TARGETS
    speed_controller
    DESTINATION lib/sensor_package
)

install(DIRECTORY launch
DESTINATION share/sensor_package
)

add_executable(speed_listener src/speed_listener.cpp)
ament_target_dependencies(speed_listener rclcpp std_msgs)
install(TARGETS
  speed_listener
  DESTINATION lib/sensor_package
)

add_executable(speed_sensor src/speed_sensor.cpp)
ament_target_dependencies(speed_sensor rclcpp std_msgs)

install(TARGETS
  speed_controller
  speed_sensor
  DESTINATION lib/sensor_package
)

add_executable(controller src/controller.cpp)
ament_target_dependencies(controller rclcpp std_msgs)

install(TARGETS
  controller
  DESTINATION lib/sensor_package
)

ament_package()
