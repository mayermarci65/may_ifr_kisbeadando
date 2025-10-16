from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='sensor_package',
            executable='speed_sensor',
            name='speed_sensor_node',
            output='screen'
        ),
        Node(
            package='sensor_package',
            executable='speed_controller',
            name='speed_controller_node',
            output='screen'
        ),
        Node(
            package='sensor_package',
            executable='speed_listener',
            name='speed_listener',
            output='screen'
        ),
    ])
