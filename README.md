# Chat-Server
Features:
1. User Management:
Create a system for user registration and authentication.
Store user information, such as username and password hashes, securely.

2. Messaging Channels:
Implement the concept of different channels for conversations.
Channels can be public (accessible to all users) or private (invitation-based or restricted access).

3. Real-time Messaging:
Enable real-time messaging between users within a channel.
Utilize a simple publish-subscribe pattern for message distribution.

4. Command Line Interface (CLI):
Develop a user-friendly command line interface for interaction.
Use std::cout and std::cin for displaying messages and gathering user input.

5. Message Persistence:
Implement a basic message persistence system to store chat history.
Use file handling (e.g., std::fstream) to save and load messages.

6. User Commands:
Allow users to perform actions like joining channels, sending messages, and viewing chat history.

C++ Features and Project Structure:

1. Object-Oriented Approach:
Use classes to represent User, Channel, and Message entities.
Encapsulate functionality related to each entity within its respective class.

2. Standard Template Library (STL):
Leverage STL containers (e.g., std::vector, std::map) for managing user lists, channel lists, and storing messages.

3. Networking:
Explore C++ networking libraries for basic client-server communication.
Implement a simple server to manage user connections and handle message distribution.

4. Error Handling:
Implement basic error handling mechanisms, such as checking for the existence of channels or handling invalid user input.
