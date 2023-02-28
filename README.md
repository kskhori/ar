# ar
This Node is used to actuate linear actuator by ros_controller.
When desired position of linear actuator is published, this node subscribe it and convert to joint position.
This value can be used joint controller(position control)

And published joint is down below.
- Joint Name : PCS9S330
- Joint Frame: PCS9S330
- Desired Actuation Time: 0.1s

## Getting started
```
git clone https://gitlab.cds.tohoku.ac.jp/horippy/ar.git
```
## Add your files

```
cd existing_repo
git remote add origin https://gitlab.cds.tohoku.ac.jp/horippy/ar.git
git branch -M main
git push -uf origin main
```

## Run the Node
```
rosrun sample_c sample_c_publisher
```

### Node List
- sample_c_publisher       
- seed_command_publisher   : Desired Actuation Time = 0.1s
- seed_command_publisher2  : Desired Actuation Time = 0.2s
- seed_command_publisher3  : Desired Actuation Time = 0.3s

## Information
--------------------------------------------------------------------------------
Node [/sample_c_publisher]

Publications:
 * /rosout [rosgraph_msgs/Log]
 * /seed/seed_controller/command [trajectory_msgs/JointTrajectory]

Subscriptions:
 * /thk_slider_des [std_msgs/Int32]
