# MCUDev

## Template Usage

1. Copy `template/STM32F103C8T6` to `Projects` and rename it to the new project name.
2. Edit the following content in `<Project>/CMakeLists.txt`:

    ```cmake
        set(CHIP_TYPE "STM32F103C8T6")
        set(MCU_PROJECT_NAME "MCUDev-Template")
    ```

3. Add the corresponding `startup` and `ld` scripts according to the chip type.

4. Add a new configuration in `.vscode/launch.json`.

5. Edit the `<Project>/lib/CMakeLists.txt` file to configure the corresponding Standard Peripheral Library or HAL Library for your chip.

6. If required, use the `template/HAL/xx_hal_conf_template.h` file for your HAL configuration.

## Libraries

- STM32 Library form STM32CubeMX
