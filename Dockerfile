FROM ubuntu:latest
EXPOSE 3030
#workdir mi mette in app come cartella di lavoro
WORKDIR /app
#qui copio main(eseguibile) e matrix.txt dentro il container 
COPY src/build/main .
COPY src/matrix.txt .