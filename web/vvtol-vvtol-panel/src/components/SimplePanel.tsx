import React, { useEffect, useRef } from 'react';
import { PanelProps } from '@grafana/data';
import { SimpleOptions } from 'types';
import { css, cx } from '@emotion/css';
import { useStyles2, useTheme2 } from '@grafana/ui';
import { PanelDataErrorView } from '@grafana/runtime';
import { setupThreeJS } from './useThreeJS';
import { generateCoordinatesFromData, drawVehicleTrace, generateCoordinates } from './vehicleTraceHelpers';

// import { generateCoordinates, drawVehicleTrace } from './vehicleTraceHelpers';

interface Props extends PanelProps<SimpleOptions> {}

const getStyles = () => {
  return {
    wrapper: css`
      font-family: Open Sans;
      position: relative;
    `,
    svg: css`
      position: absolute;
      top: 0;
      left: 0;
    `,
    textBox: css`
      position: absolute;
      bottom: 0;
      left: 0;
      padding: 10px;
    `,
    canvas: css`
      display: block;
    `,
  };
};

export const SimplePanel: React.FC<Props> = ({ options, data, width, height, fieldConfig, id }) => {
  const theme = useTheme2();
  const styles = useStyles2(getStyles);
  const canvasRef = useRef<HTMLCanvasElement>(null);

  useEffect(() => {
    if (canvasRef.current && data.series.length > 0) {
      const scene = setupThreeJS(canvasRef.current, width, height, theme.colors.primary.main);
      
      // Generate coordinates from the data
      const coordinates = generateCoordinatesFromData(data.series, 10); // Adjust the number of sample points as needed
      // const coordinates = generateCoordinates({x: 1, y: 2, z: 3}, {x: 4, y: 5, z: 6}, 10);
      // Draw the vehicle trace
      drawVehicleTrace(scene, coordinates);
    }
  }, [data, width, height, theme.colors.primary.main]);

  if (data.series.length === 0) {
    return <PanelDataErrorView fieldConfig={fieldConfig} panelId={id} data={data} needsStringField />;
  }

  return (
    <div
      className={cx(
        styles.wrapper,
        css`
          width: ${width}px;
          height: ${height}px;
        `
      )}
    >
      <canvas ref={canvasRef} className={styles.canvas} width={width} height={height}></canvas>
    </div>
  );
};
