CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra
CXXXFLAGS = -Wall -Werror -Wextra -lncurses
NAME = pewPew

SRC = src/Sprite.cpp src/Obstacle.cpp src/Projectile.cpp src/main.cpp src/Ship.cpp src/Window.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
