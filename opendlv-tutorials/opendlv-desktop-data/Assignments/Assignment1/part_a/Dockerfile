# # Build
# FROM ubuntu:20.04 as builder
# RUN apt update && \
#     apt install -y \
#         ca-certificates \
#         cmake \
#         g++ \
#         make \
#         software-properties-common
# RUN add-apt-repository ppa:chrberger/libcluon
# ADD . /opt/sources
# WORKDIR /opt/sources
# RUN mkdir /tmp/build && cd /tmp/build && \
#     cmake /opt/sources && \
#     make && make test && cp helloworld /tmp

# # Deploy
# FROM ubuntu:20.04
# RUN apt update && \
#     apt install -y \
#         libstdc++6
# COPY --from=builder /tmp/helloworld /usr/bin
# CMD ["/usr/bin/helloworld"]

# Build
FROM ubuntu:20.04 as builder
RUN apt update && \
    apt install -y \
        ca-certificates \
        cmake \
        g++ \
        make \
        software-properties-common
RUN add-apt-repository ppa:chrberger/libcluon
RUN apt update && \
    apt install -y libcluon
ADD . /opt/sources
WORKDIR /opt/sources
RUN mkdir /tmp/build && cd /tmp/build && \
    cmake /opt/sources && \
    make && make test && cp helloworld /tmp

# Deploy
FROM ubuntu:20.04
RUN apt update && \
    apt install -y \
        libstdc++6
COPY --from=builder /tmp/helloworld /usr/bin
CMD ["/usr/bin/helloworld"]
