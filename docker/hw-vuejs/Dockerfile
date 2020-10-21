FROM ubuntu:20.04

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update \
    && apt-get install -y \
        git \
        curl \
        wget \
        vim \
    && rm -rf /var/lib/apt/lists/*

RUN curl -sL https://deb.nodesource.com/setup_15.x | bash - && apt-get install -y nodejs
RUN npm install -g @vue/cli && vue create app -d
WORKDIR /app
EXPOSE 8080
CMD ["run", "run", "serve"]