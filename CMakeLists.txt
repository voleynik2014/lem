cmake_minimum_required(VERSION 3.6)
project(lem_in1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        includes/lem_in.h
        libft/ft_atoi.c
        libft/ft_bzero.c
        libft/ft_color.c
        libft/ft_get_next_line.c
        libft/ft_isalnum.c
        libft/ft_isalpha.c
        libft/ft_isascii.c
        libft/ft_isdigit.c
        libft/ft_isprint.c
        libft/ft_itoa.c
        libft/ft_itoa_base.c
        libft/ft_itoa_ll.c
        libft/ft_lstadd.c
        libft/ft_lstdel.c
        libft/ft_lstdelone.c
        libft/ft_lstiter.c
        libft/ft_lstmap.c
        libft/ft_lstnew.c
        libft/ft_memalloc.c
        libft/ft_memccpy.c
        libft/ft_memchr.c
        libft/ft_memcmp.c
        libft/ft_memcpy.c
        libft/ft_memdel.c
        libft/ft_memmove.c
        libft/ft_memset.c
        libft/ft_padding.c
        libft/ft_padding_str.c
        libft/ft_printf.c
        libft/ft_printf.h
        libft/ft_put_uintmax.c
        libft/ft_putchar.c
        libft/ft_putchar_fd.c
        libft/ft_putendl.c
        libft/ft_putendl_fd.c
        libft/ft_putnbr.c
        libft/ft_putnbr_fd.c
        libft/ft_putnstr.c
        libft/ft_putstr.c
        libft/ft_putstr_fd.c
        libft/ft_putwchar.c
        libft/ft_putwchar_fd.c
        libft/ft_specifiers.c
        libft/ft_specifiers2.c
        libft/ft_squere.c
        libft/ft_strcat.c
        libft/ft_strchr.c
        libft/ft_strclr.c
        libft/ft_strcmp.c
        libft/ft_strcpy.c
        libft/ft_strdel.c
        libft/ft_strdup.c
        libft/ft_strequ.c
        libft/ft_striter.c
        libft/ft_striteri.c
        libft/ft_strjoin.c
        libft/ft_strlcat.c
        libft/ft_strlen.c
        libft/ft_strmap.c
        libft/ft_strmapi.c
        libft/ft_strncat.c
        libft/ft_strncmp.c
        libft/ft_strncpy.c
        libft/ft_strndup.c
        libft/ft_strnequ.c
        libft/ft_strnew.c
        libft/ft_strnstr.c
        libft/ft_strrchr.c
        libft/ft_strsplit.c
        libft/ft_strstr.c
        libft/ft_strsub.c
        libft/ft_strtrim.c
        libft/ft_tolower.c
        libft/ft_toupper.c
        libft/ft_type_di.c
        libft/ft_type_ox.c
        libft/ft_type_s.c
        libft/ft_type_wchar.c
        libft/get_next_line.h
        libft/libft.h
        libft/printflib.h
        src/ft_build_new_way.c
        src/ft_create.c
        src/ft_lem_in.c
        src/ft_read.c src/ft_calc_optimal_way.c src/permutation.c src/some_calc.c src/ft_realloc_lemin.c src/ft_delete_lemin_things.c src/ft_validation.c src/ft_print_result.c)

include_directories(includes)

add_executable(lem_in1 ${SOURCE_FILES})