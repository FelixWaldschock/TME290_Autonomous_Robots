# Assignment C - 1 part & B

Create an OpenDLV microservice with the name opendlv-logic-CID where CID is replaced with your Chalmers ID. The microservice should use the OpenDLV standard message set as found hereLinks to an external site.. It should use and OD4 session to listen for incoming data off type opendlv.proxy.GroundSpeedRequest on conference ID (cid) 132 and when such message is received it should, on the same conference, send back a message opendlv.proxy.GroundSpeedReading with the value of the request multiplied with a floating point number of your choice (not 1.0). No other messages should be accepted as input.

In order to use the OD4 session inside the lambda function, you need to expose it by using the lambda capture block, as for example [&od4].

Create a Docker image from the microservice and submit it in a tar file as described in the lectures. Also submit your source code. Incorrect code indentation or bad code quality might affect your grade negatively. Use the template found hereLinks to an external site. as a starting point.

 

c) Enable CI/CD for the microservice created in part (b) using your Chalmers GitLab account. Enable cross compilation for linux/amd64 and linux/arm64. In your report, give the command needed to run your microservice from the docker registry, and provide a screenshot of your GitLab container registry showing your Docker image, as well as a screenshot when your run your microservice from the terminal. Also submit your source code.
