cmake_minimum_required(VERSION 3.9)
project(Portfel C CXX)

set(CMAKE_CXX_STANDARD 11)

add_executable(Portfel main.cpp Portfel.cpp Portfel.h Aktywa.cpp Aktywa.h listaAktywow.h Lokata.cpp Lokata.h FunduszInwestycyjny.cpp FunduszInwestycyjny.h Nieruchomosc.cpp Nieruchomosc.h Waluta.cpp Waluta.h Akcje.cpp Akcje.h Kontrakt.cpp Kontrakt.h)