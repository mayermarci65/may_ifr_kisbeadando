from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='sensor_package',
            executable='speed_controller',
            name='speed_controller_node'
        ),
        Node(
            package='sensor_package',
            executable='controller',
            name='controller_node'
        )
    ])
