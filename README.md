# ar

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
- seed_command_publisher   
- seed_command_publisher2  
- seed_command_publisher3

## Information
--------------------------------------------------------------------------------
Node [/sample_c_publisher]

Publications:
 * /rosout [rosgraph_msgs/Log]
 * /seed/seed_controller/command [trajectory_msgs/JointTrajectory]
