// #include <CL/cl.h>
// #include <unistd.h>

// void GPU_Enums()
// {
//     cl_uint platform_count = 0;

//     if (clGetPlatformIDs(0, 0, &platform_count) != CL_SUCCESS)
//         return;

//     if (platform_count == 0)
//         return;

//     cl_platform_id platforms[8];
//     if (platform_count > 8)
//         platform_count = 8;

//     if (clGetPlatformIDs(platform_count, platforms, 0) != CL_SUCCESS)
//         return;

//     for (cl_uint i = 0; i < platform_count; ++i)
//     {
//         cl_uint device_count = 0;

//         if (clGetDeviceIDs(platforms[i],
//                            CL_DEVICE_TYPE_ALL,
//                            0,
//                            0,
//                            &device_count) != CL_SUCCESS)
//             continue;

//         if (device_count == 0)
//             continue;

//         cl_device_id devices[16];
//         if (device_count > 16)
//             device_count = 16;

//         if (clGetDeviceIDs(platforms[i],
//                            CL_DEVICE_TYPE_ALL,
//                            device_count,
//                            devices,
//                            0) != CL_SUCCESS)
//             continue;

//         for (cl_uint d = 0; d < device_count; ++d)
//         {
//             char name[128];
//             char vendor[128];
//             cl_device_type type;
//             cl_uint compute_units;
//             cl_ulong global_mem;

//             clGetDeviceInfo(devices[d], CL_DEVICE_NAME,
//                             sizeof(name), name, 0);

//             clGetDeviceInfo(devices[d], CL_DEVICE_VENDOR,
//                             sizeof(vendor), vendor, 0);

//             clGetDeviceInfo(devices[d], CL_DEVICE_TYPE,
//                             sizeof(type), &type, 0);

//             clGetDeviceInfo(devices[d], CL_DEVICE_MAX_COMPUTE_UNITS,
//                             sizeof(compute_units), &compute_units, 0);

//             clGetDeviceInfo(devices[d], CL_DEVICE_GLOBAL_MEM_SIZE,
//                             sizeof(global_mem), &global_mem, 0);

//             /* Replace this with your own logging system */
//             write(1, "GPU Found:\n", 11);
//             write(1, name, sizeof(name));
//             write(1, "\n", 1);
//         }
//     }
// }

// int main(int argc, const char *argv[]){
    
//     GPU_Enums();

//     return 0;
// }


#include <CL/cl.h>
#include <unistd.h>

static void write_str(const char* s)
{
    size_t len = 0;
    while (s[len] != 0)
        ++len;

    write(1, s, len);
}

static void write_u64(cl_ulong value)
{
    char buf[32];
    int i = 30;
    buf[31] = 0;

    if (value == 0)
    {
        write(1, "0", 1);
        return;
    }

    while (value > 0 && i >= 0)
    {
        buf[i--] = '0' + (value % 10);
        value /= 10;
    }

    write(1, &buf[i + 1], 30 - i);
}

cl_uint GPU_Enums(void)
{
    cl_uint total_devices = 0;

    cl_uint platform_count = 0;
    if (clGetPlatformIDs(0, 0, &platform_count) != CL_SUCCESS)
        return 0;

    if (platform_count == 0)
        return 0;

    if (platform_count > 8)
        platform_count = 8;

    cl_platform_id platforms[8];

    if (clGetPlatformIDs(platform_count, platforms, 0) != CL_SUCCESS)
        return 0;

    for (cl_uint i = 0; i < platform_count; ++i)
    {
        cl_uint device_count = 0;

        if (clGetDeviceIDs(platforms[i],
                           CL_DEVICE_TYPE_ALL,
                           0,
                           0,
                           &device_count) != CL_SUCCESS)
            continue;

        if (device_count == 0)
            continue;

        if (device_count > 16)
            device_count = 16;

        cl_device_id devices[16];

        if (clGetDeviceIDs(platforms[i],
                           CL_DEVICE_TYPE_ALL,
                           device_count,
                           devices,
                           0) != CL_SUCCESS)
            continue;

        for (cl_uint d = 0; d < device_count; ++d)
        {
            char name[128];
            char vendor[128];
            size_t name_size = 0;
            size_t vendor_size = 0;
            cl_uint compute_units = 0;
            cl_ulong global_mem = 0;

            if (clGetDeviceInfo(devices[d],
                                CL_DEVICE_NAME,
                                sizeof(name),
                                name,
                                &name_size) != CL_SUCCESS)
                continue;

            if (clGetDeviceInfo(devices[d],
                                CL_DEVICE_VENDOR,
                                sizeof(vendor),
                                vendor,
                                &vendor_size) != CL_SUCCESS)
                continue;

            if (clGetDeviceInfo(devices[d],
                                CL_DEVICE_MAX_COMPUTE_UNITS,
                                sizeof(compute_units),
                                &compute_units,
                                0) != CL_SUCCESS)
                continue;

            if (clGetDeviceInfo(devices[d],
                                CL_DEVICE_GLOBAL_MEM_SIZE,
                                sizeof(global_mem),
                                &global_mem,
                                0) != CL_SUCCESS)
                continue;

            write_str("================================\n");
            write_str("GPU Found:\n");

            write_str("Name: ");
            if (name_size > 0)
                write(1, name, name_size - 1);
            write_str("\n");

            write_str("Vendor: ");
            if (vendor_size > 0)
                write(1, vendor, vendor_size - 1);
            write_str("\n");

            write_str("Compute Units: ");
            write_u64(compute_units);
            write_str("\n");

            write_str("Global Memory (bytes): ");
            write_u64(global_mem);
            write_str("\n");

            ++total_devices;
        }
    }

    return total_devices;
}

int main(void)
{
    cl_uint devices = GPU_Enums();

    if (devices == 0)
        write_str("No OpenCL devices found.\n");

    return 0;
}