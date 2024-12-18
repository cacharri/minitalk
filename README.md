# Minitalk

El proyecto **Minitalk** forma parte del currículo de 42 y tiene como objetivo implementar un sistema de comunicación entre procesos mediante señales de UNIX. Este proyecto es una introducción práctica a los fundamentos de la comunicación entre procesos (IPC) y el manejo de señales en un entorno POSIX.

---

## 🚀 Descripción del Proyecto

Minitalk consiste en desarrollar un cliente y un servidor que se comuniquen utilizando las señales `SIGUSR1` y `SIGUSR2`. El servidor debe recibir mensajes enviados por el cliente y mostrarlos correctamente en la salida estándar.

---

## 🔧 Requisitos

- **Entorno**: Linux o MacOS.
- **Lenguaje**: C.
- **Señales utilizadas**:
  - `SIGUSR1`: Representa un bit de valor `0`.
  - `SIGUSR2`: Representa un bit de valor `1`.

---

## 📁 Estructura del Proyecto

```plaintext
minitalk/
├── client.c         # Implementación del cliente
├── server.c         # Implementación del servidor
├── includes/        # Archivos de cabecera
├── Makefile         # Sistema de compilación
└── README.md        # Documentación
```

---

## 🛠️ Uso

1. Clona el repositorio:
   ```bash
   git clone https://github.com/cacharri/minitalk.git
   cd minitalk
   ```

2. Compila el proyecto:
   ```bash
   make
   ```

3. Ejecuta el servidor:
   ```bash
   ./server
   ```

   El servidor imprimirá su PID en la salida estándar. Usa este PID para comunicarte con el cliente.

4. Envía un mensaje desde el cliente al servidor:
   ```bash
   ./client <PID_SERVIDOR> "Tu mensaje aquí"
   ```

---

## 🌟 Características

- Comunicación confiable utilizando señales UNIX.
- Manejo robusto de errores (e.g., PID inválidos, mensajes largos).
- Compatibilidad con múltiples mensajes consecutivos.

---

## 🧪 Testing

1. Lanza el servidor:
   ```bash
   ./server
   ```

2. Envía diferentes mensajes:
   ```bash
   ./client <PID_SERVIDOR> "Hola, mundo!"
   ./client <PID_SERVIDOR> "Mensaje de prueba"
   ```

3. Prueba escenarios como:
   - Mensajes largos.
   - Enviar mensajes consecutivos.
   - Introducir un PID inválido para verificar el manejo de errores.

---
