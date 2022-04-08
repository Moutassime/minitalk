
INC = minitalk.h

SERVER_SRCS = server.c srcs/myprint.c
CLIENT_SRCS = client.c srcs/ft_atoi.c srcs/myprint.c

SERVER_SRCS_BONUS = server_bonus.c srcs/myprint.c
CLIENT_SRCS_BONUS = client_bonus.c srcs/ft_atoi.c srcs/myprint.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

SERVER_OBJS_BONUS = $(SERVER_SRCS_BONUS:.c=.o)
CLIENT_OBJS_BONUS = $(CLIENT_SRCS_BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf 

all: server client 

bonus: server_bonus client_bonus

client:$(CLIENT_OBJS)
	@$(CC) $(CFLAGS) $(CLIENT_OBJS) -o client
	@echo "Client cree avec succes"

server:$(SERVER_OBJS)
	@$(CC) $(CFLAGS) $(SERVER_OBJS) -o server
	@echo "server cree avec succes"

client_bonus:$(CLIENT_OBJS_BONUS)
	@$(CC) $(CFLAGS) $(CLIENT_OBJS_BONUS) -o client_bonus
	@echo "client bonus cree avec succes"

server_bonus:$(SERVER_OBJS_BONUS)
	@$(CC) $(CFLAGS) $(SERVER_OBJS_BONUS) -o server_bonus
	@echo "server bonus cree avec succes"

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(SERVER_OBJS) $(CLIENT_OBJS) $(SERVER_OBJS_BONUS) $(CLIENT_OBJS_BONUS)
	@echo "object files supprimer avec succes"
	@echo "object bonus files supprimer avec succes"

fclean:clean
	@$(RM) client server client_bonus server_bonus
	@echo "client/client_bonus et server/server_bonus supprime avec succes"

re: fclean all

.PHONY: all client server_bonus client_bonus clean fclean re
