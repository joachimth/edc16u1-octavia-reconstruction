// Internal-flash boot/startup (reset vector + r13 setup @0x20C)

// ==== reset_vector @0x00000000 ====

/* WARNING: Control flow encountered bad instruction data */

void reset_vector(void)

{
  FUN_00001284();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

