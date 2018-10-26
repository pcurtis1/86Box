/*
 * 86Box	A hypervisor and IBM PC system emulator that specializes in
 *		running old operating systems and software designed for IBM
 *		PC systems and compatibles from 1981 through fairly recent
 *		system designs based on the PCI bus.
 *
 *		Emulation of SCSI fixed and removable disks.
 *
 * Version:	@(#)scsi_disk.h	1.0.7	2018/10/26
 *
 * Author:	Miran Grca, <mgrca8@gmail.com>
 *		Copyright 2017,2018 Miran Grca.
 */


typedef struct {
    mode_sense_pages_t ms_pages_saved;

    hard_disk_t *drv;

    uint8_t *temp_buffer,
	    pad[16],	/* This is atapi_cdb in ATAPI-supporting devices,
			   and pad in SCSI-only devices. */
	    current_cdb[16],
	    sense[256];

    uint8_t status, phase,
	    error, id,
	    pad0, pad1,
	    pad2, pad3;

    uint16_t request_length, pad4;

    int requested_blocks, packet_status,
	total_length, do_page_save,
	unit_attention;

    uint32_t sector_pos, sector_len,
	     packet_len, pos;

    int64_t callback;
} scsi_disk_t;


extern scsi_disk_t *scsi_disk[HDD_NUM];


extern void	scsi_disk_hard_reset(void);
extern void	scsi_disk_close(void);
