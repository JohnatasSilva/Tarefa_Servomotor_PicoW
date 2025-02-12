# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
# Arquivo CMakeLists.txt atualizado para Raspberry Pi Pico W

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Configuração do ambiente no Windows e Linux/macOS
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()

# Definições do SDK e Toolchain
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)

# Caminho do arquivo de configuração do VS Code (se existir)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()

# Definição da placa utilizada (Pico W)
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Importação do SDK do Raspberry Pi Pico
include(pico_sdk_import.cmake)

# Nome do projeto
project(tarefa_servomotor_06_02 C CXX ASM)

# Inicialização do SDK
pico_sdk_init()

# Definição do executável e inclusão do código-fonte principal
add_executable(tarefa_servomotor_06_02
    tarefa_servomotor_06_02.c
)

# Nome e versão do programa
pico_set_program_name(tarefa_servomotor_06_02 "Tarefa_servomotor_06_02")
pico_set_program_version(tarefa_servomotor_06_02 "0.1")

# Habilitação de saída via UART e USB (ajuste conforme necessário)
pico_enable_stdio_uart(tarefa_servomotor_06_02 1)
pico_enable_stdio_usb(tarefa_servomotor_06_02 1)

# Adicionar bibliotecas padrão e PWM ao projeto
target_link_libraries(tarefa_servomotor_06_02
    pico_stdlib
    hardware_pwm  # Biblioteca necessária para PWM
)

# Incluir diretórios do projeto
target_include_directories(tarefa_servomotor_06_02 PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

# Adicionar saídas extras (como UF2)
pico_add_extra_outputs(tarefa_servomotor_06_02)
