import React, { useEffect, useRef, useState } from 'react';
import { PanelProps } from '@grafana/data';
import { SimpleOptions } from 'types';
import { css, cx } from '@emotion/css';
import { useStyles2, useTheme2 } from '@grafana/ui';
import { PanelDataErrorView } from '@grafana/runtime';
import * as THREE from 'three';
import { setupThreeJS } from './useThreeJS';
import { generateCoordinatesFromData, createVehicleTraceObjects } from './vehicleTraceHelpers';

interface Props extends PanelProps<SimpleOptions> {}

const getStyles = () => {
  return {
    wrapper: css`
      font-family: Open Sans;
      position: relative;
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
  const sceneRef = useRef<THREE.Scene | null>(null);
  const traceGroupRef = useRef<THREE.Group | null>(null);

  const [isSceneSetup, setIsSceneSetup] = useState(false);

  useEffect(() => {
    if (canvasRef.current && !isSceneSetup) {
      sceneRef.current = setupThreeJS(canvasRef.current, width, height, theme.colors.primary.main);
      traceGroupRef.current = new THREE.Group();
      sceneRef.current.add(traceGroupRef.current);
      setIsSceneSetup(true);
    }
  }, [width, height, theme.colors.primary.main, isSceneSetup]);

  useEffect(() => {
    if (isSceneSetup && sceneRef.current && traceGroupRef.current && data.series.length > 0) {
      // Clear old trace objects
      traceGroupRef.current.clear();

      // Generate new trace objects
      const coordinates = generateCoordinatesFromData(data.series, 10);
      const newTraceObjects = createVehicleTraceObjects(coordinates);
      
      // Add new trace objects to the group
      newTraceObjects.forEach(obj => traceGroupRef.current?.add(obj));
    }
  }, [data, isSceneSetup]);

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